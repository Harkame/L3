// compiler avec les options : -Wall -std=c++11
// Exercice 6,
#include <thread>
#include <iostream>
#include <queue>
#include <future>
#include <condition_variable>
#include <mutex>

using namespace std;

class Producteur
{
  public:
    void operator()(queue<int> &p_buffer, bool& p_fini, mutex& p_mutex_write, condition_variable& p_condition_added, mutex& p_mutex_fini) const
    {
      for (int t_index = 1; t_index <= 5; ++t_index)
      {
        p_mutex_write.lock();
        p_buffer.push(t_index);
        p_mutex_write.unlock();
        p_condition_added.notify_all();
      }

      p_mutex_fini.lock();
      p_fini = true;
      p_mutex_fini.unlock();
    }
};

class Consommateur
{
  public:
    int operator()(queue<int> &p_buffer, bool &p_fini, mutex& p_mutex_read, condition_variable& p_condition_added, mutex& p_mutex_fini) const
    {
      int r_sum = 0;

      p_mutex_fini.lock();

      do
      {
        p_mutex_fini.unlock();

        {unique_lock<mutex> t_unique_lock(p_mutex_read);

          if(p_buffer.empty())
            p_condition_added.wait(t_unique_lock);

          r_sum += p_buffer.front();
          p_buffer.pop();
        }

      p_mutex_fini.lock();

    }while(!p_fini);

    p_mutex_fini.unlock();

    while(!p_buffer.empty())
    {
      r_sum += p_buffer.front();
      p_buffer.pop();
    }
      return r_sum;
    }
  };

void foo()
{
  Producteur t_producteur;
  Consommateur t_consomateur;

  queue<int> t_buffer;
  bool t_fin = false;

  mutex t_mutex;
  mutex t_mutex_fini;

  condition_variable t_condition_added;

  thread t1(t_producteur, ref(t_buffer), ref(t_fin), ref(t_mutex), ref(t_condition_added), ref(t_mutex_fini));

  future<int> resultat = async(launch::async, t_consomateur, ref(t_buffer), ref(t_fin), ref(t_mutex), ref(t_condition_added), ref(t_mutex_fini));

  resultat.wait();

  t1.join();

  int res = resultat.get();

  cout << "Somme : " << res << endl;
}

int main()
{
  foo();

  return 0;
}
