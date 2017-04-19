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
    void operator()(queue<int> &buffer, bool &fini) const
    {
      for (int i = 1; i <= 30; ++i)
        buffer.push(i);

      fini = true;
    }
};

class Consommateur
{
  public:
    int operator()(queue<int> &buffer, bool &fini, mutex& verrou condition_variable& cond) const
    {
      int summ = 0;
      {
        unique_lock<mutex> ul(verrou);
        if(!ready)
          cond.wait();
      }

      while (!buffer.empty())
      {
        summ+=buffer.front();
        buffer.pop();
      }

      return summ;
};

int main()
{
  Producteur prod;
  Consommateur cons;

  queue<int> buffer;
  bool fin = false;

  thread t1(prod, ref(buffer), ref(fin));
  future<int> resultat = async(cons, ref(buffer), ref(fin));
  resultat.wait();

  t1.join();

  int res = resultat.get();

  cout << "Somme : " << res << endl;

  return 0;
}
