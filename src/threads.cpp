#include "util.hpp"

#include <future>

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

  constexpr int maxPrime(100000);
  constexpr size_t num_runs(10);

  std::cout << "Single threaded" << std::endl;
  time([](){
    std::vector<int> p1(primes(maxPrime));
    std::vector<int> p2(primes(maxPrime));
    std::vector<int> p3(primes(maxPrime));
    std::vector<int> p4(primes(maxPrime));
    std::vector<int> p5(primes(maxPrime));
    std::vector<int> p6(primes(maxPrime));
    std::vector<int> combined(p1 + p2 + p3 + p4 + p5 + p6);
    //combined.insert(combined.end(), p1.begin(), p1.end());
    //combined.insert(combined.end(), p2.begin(), p2.end());
    //combined.insert(combined.end(), p3.begin(), p3.end());
    //combined.insert(combined.end(), p4.begin(), p4.end());
    //combined.insert(combined.end(), p5.begin(), p5.end());
    //combined.insert(combined.end(), p6.begin(), p6.end());
    std::sort(combined.begin(), combined.end());
    //print_vector(combined, ", ");
  }, num_runs);
  std::cout << "Multi threaded" << std::endl;
  time([](){
    std::future<std::vector<int> > f1 = std::async(std::launch::async, [](){ return primes(maxPrime); });
    std::future<std::vector<int> > f2 = std::async(std::launch::async, [](){ return primes(maxPrime); });
    std::future<std::vector<int> > f3 = std::async(std::launch::async, [](){ return primes(maxPrime); });
    std::future<std::vector<int> > f4 = std::async(std::launch::async, [](){ return primes(maxPrime); });
    std::future<std::vector<int> > f5 = std::async(std::launch::async, [](){ return primes(maxPrime); });
    std::future<std::vector<int> > f6 = std::async(std::launch::async, [](){ return primes(maxPrime); });
    std::vector<int> combined(f1.get() + f2.get() + f3.get() + f4.get() + f5.get() + f6.get());
    //std::vector<int> combined;
    //std::vector<int> p1(f1.get());
    //combined.insert(combined.end(), p1.begin(), p1.end());
    //std::vector<int> p2(f2.get());
    //combined.insert(combined.end(), p2.begin(), p2.end());
    //std::vector<int> p3(f3.get());
    //combined.insert(combined.end(), p3.begin(), p3.end());
    //std::vector<int> p4(f4.get());
    //combined.insert(combined.end(), p4.begin(), p4.end());
    //std::vector<int> p5(f5.get());
    //combined.insert(combined.end(), p5.begin(), p5.end());
    //std::vector<int> p6(f6.get());
    //combined.insert(combined.end(), p6.begin(), p6.end());
    std::sort(combined.begin(), combined.end());
    //print_vector(combined, ", ");
  }, num_runs);

  return 0;
}


