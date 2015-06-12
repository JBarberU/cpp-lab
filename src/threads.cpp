#include "util.hpp"

std::vector<int> primes(int maxVal)
{
  std::vector<int> p{2};
  for (size_t i(3); i <= maxVal; i += 2)
  {
    bool isPrime(true);
    for (int v : p)
    {
      if (i % v == 0)
      {
        isPrime = false;
        break;
      }
    }
    if (isPrime)
      p.push_back(i);
  }
  return p;
}

int fak(int val)
{
  return val == 1 ? 1 : val * fak(val - 1);
}


int main(int argc, char** argv)
{
  //std::future<int> foo = ;
  //std::future<void> f = std::async(std::launch::async, [](std::future<int> f_in){
    //std::cout << "Hi: " << f_in.get() << std::endl;
  //}, std::async(std::launch::async, [](){
    //std::cout << "Sleeping..." << std::endl;
    ////std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    //print_vector(primes(100000), ',');
    //return fak(10);
    //}));

  //f.wait();

  time([](){primes(100000);}, 10);

  return 0;
}


