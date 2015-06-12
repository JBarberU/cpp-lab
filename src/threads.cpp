#include <future>
#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <algorithm>

template<typename T, typename Delim_t>
void printVector(const std::vector<T> &vec, Delim_t delim)
{
  std::for_each(vec.begin(), vec.end() - 1, [delim](const T &v){
    std::cout << v << delim;
  });
  std::cout << vec.back() << std::endl;
}

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

template<typename Func>
void time(Func f, size_t iterations)
{
  std::vector<double> results;
  for (size_t i(0); i < iterations; ++i)
  {
    auto start = std::chrono::system_clock::now();
    f();
    auto stop = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = stop - start;
    results.push_back(diff.count());
  }
  std::cout << "Results: ";
  printVector(results, ", ");

  std::sort(results.begin(), results.end());
  double sum = std::accumulate(results.begin(), results.end(), 0);
  double mean = (sum / static_cast<double>(results.size()));

  double a(0.0);

  std::for_each(results.begin(), results.end(), [&a, mean](double v){
    a += (v - mean) * (v - mean);
  });

  double standar_deviation = std::sqrt(a / static_cast<double>(results.size()));

  std::cout << "Sum: " << sum << std::endl;
  std::cout << "Mean: " << mean << std::endl;
  std::cout << "Median: " << results[results.size() / 2] << std::endl;
  std::cout << "Standard deviation: " << standar_deviation << std::endl;
}

int main(int argc, char** argv)
{
  //std::future<int> foo = ;
  //std::future<void> f = std::async(std::launch::async, [](std::future<int> f_in){
    //std::cout << "Hi: " << f_in.get() << std::endl;
  //}, std::async(std::launch::async, [](){
    //std::cout << "Sleeping..." << std::endl;
    ////std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    //printVector(primes(100000), ',');
    //return fak(10);
    //}));

  //f.wait();

  time([](){primes(100000);}, 10);

  return 0;
}


