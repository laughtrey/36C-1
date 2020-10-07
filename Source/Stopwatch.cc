#include "Stopwatch.h"
Stopwatch::Stopwatch() { m_total_time = 0; }
int Stopwatch::linear_stopwatch(const std::vector<Book> &nb,
                                const std::vector<Book> &r) {
  auto start = std::chrono::high_resolution_clock::now();
  int count = linear_search(nb, r);
  auto end = std::chrono::high_resolution_clock::now();
  double total_time =
      std::chrono::duration<double, std::micro>(end - start).count();
  m_total_time = total_time;
  return count;
}
int Stopwatch::binary_stopwatch(std::vector<Book> &nb,
                                const std::vector<Book> &r) {
  auto start = std::chrono::high_resolution_clock::now();
  std::sort(nb.begin(), nb.end());
  int count = binary_search_parse(nb, r);
  auto end = std::chrono::high_resolution_clock::now();
  double total_time =
      std::chrono::duration<double, std::micro>(end - start).count();
  m_total_time = total_time;
  return count;
}
std::ostream &operator<<(std::ostream &stream, const Stopwatch stopwatch) {
  return stream << "CPU time: " << stopwatch.m_total_time << " microseconds";
}