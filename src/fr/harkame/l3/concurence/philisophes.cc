#include <thread>
#include <iostream>
#include <mutex>
#include <functional>

using namespace std;

class Philo
{
public:
  void operator()(mutex &baguetteG, mutex &baguetteD, int place) const
  {
    while(true)
    {
      this_thread::sleep_for(chrono::milliseconds(1));//je pense

      cout<< "Philisophe " << place << " pense" <<endl;

      if(baguetteG.try_lock())
        if(!baguetteD.try_lock())
          baguetteG.unlock();
        else
        {
          cout<< "Philisophe " << place << " mange"<<endl;

          this_thread::sleep_for(chrono::milliseconds(place));//je mange

          baguetteG.unlock();
          baguetteD.unlock();
        }
    }
  }
};



int main()
{
  thread tphilos[5];
  Philo philos[5];
  mutex baguettes[5];

  for(int i = 0; i < 4; i++)
    tphilos[i] = thread(philos[i], ref(baguettes[i+1]),  ref(baguettes[i]), i+1);

  tphilos[4] = thread(philos[4], ref(baguettes[0]),  ref(baguettes[4]), 5);

  for(int i=0; i < 5; i++)
    tphilos[i].join();

  return 0;
}
