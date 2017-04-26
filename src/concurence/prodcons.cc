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
    void operator()(queue<int> &p_queue, bool& p_ended, mutex& p_mutex_write, condition_variable& p_condition_added, mutex& p_mutex_ended) const
    {
      for (int t_index = 1; t_index <= 3; ++t_index)
      {
        p_mutex_write.lock();
        p_queue.push(t_index);
        p_mutex_write.unlock();

        p_condition_added.notify_all();
      }

      p_mutex_ended.lock();
      p_ended = true;
      p_mutex_ended.unlock();
    }
};

class Consommateur
{
  public:
    int operator()(queue<int> &p_queue, bool &p_ended, mutex& p_mutex_read, condition_variable& p_condition_added, mutex& p_mutex_ended) const
    {
      int r_sum = 0;

      p_mutex_ended.lock();

      do
      {
        p_mutex_ended.unlock();

        {unique_lock<mutex> t_unique_lock(p_mutex_read);

          if(p_queue.empty())
            p_condition_added.wait(t_unique_lock);

          r_sum += p_queue.front();
          p_queue.pop();
        }

      p_mutex_ended.lock();

      }while(!p_ended);

      p_mutex_ended.unlock();

      while(!p_queue.empty())
      {
        r_sum += p_queue.front();
        p_queue.pop();
      }

      return r_sum;
    }
  };

void foo()
{
  Producteur t_producteur;
  Consommateur t_consomateur;
  Consommateur t_consomateur_2;

  queue<int> t_queue;
  bool t_ended = false;

  mutex t_mutex;
  mutex t_mutex_fini;

  condition_variable t_condition_added;

  thread t1(t_producteur, ref(t_queue), ref(t_ended), ref(t_mutex), ref(t_condition_added), ref(t_mutex_fini));

  future<int> resultat = async(launch::async, t_consomateur, ref(t_queue), ref(t_ended), ref(t_mutex), ref(t_condition_added), ref(t_mutex_fini));

  resultat.wait();

  t1.join();

  cout << "Somme : " << resultat.get() << endl;
}

int main()
{
  foo();

  return 0;
}
