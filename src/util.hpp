#include <algorithm>
#include <vector>
#include <chrono>
#include <iostream>

template<typename T, typename Delim_t>
void print_vector(const std::vector<T> &vec, Delim_t delim)
{
  std::for_each(vec.begin(), vec.end() - 1, [delim](const T &v){
    std::cout << v << delim;
  });
  std::cout << vec.back() << std::endl;
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
  print_vector(results, ", ");

  std::sort(results.begin(), results.end());
  double sum = std::accumulate(results.begin(), results.end(), 0.0);
  double mean = (sum / static_cast<double>(results.size()));

  double a(0.0);

  std::for_each(results.begin(), results.end(), [&a, mean](double v){
    a += (v - mean) * (v - mean);
  });

  double standard_deviation = std::sqrt(a / static_cast<double>(results.size()));

  std::cout << "Sum: " << sum << std::endl;
  std::cout << "Mean: " << mean << std::endl;
  std::cout << "Median: " << results[results.size() / 2] << std::endl;
  std::cout << "Standard deviation: " << standard_deviation << std::endl;
}

template <typename T>
std::vector<T> operator +(const std::vector<T> &rhs, const std::vector<T> &lhs)
{
  std::vector<T> result;
  result.reserve(lhs.size() + rhs.size());
  result.insert(result.end(), lhs.begin(), lhs.end());
  result.insert(result.end(), rhs.begin(), rhs.end());
  return result;
}
