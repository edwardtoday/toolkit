#include "random.h"
#pragma warning(push, 0)
#include "assert.h"
#include <iostream>
#include <ctime>
#pragma warning(pop)

int main() {
  std::clock_t    start;
  start = std::clock();

  for (int i = 0; i < 1000000; ++i) {
    int j = qingpei::toolkit::random::random_in_range(0, 100);
    //std::cout << j << ',';
  }

  std::cout << "Time: " << (std::clock() - start) / (double)(
              CLOCKS_PER_SEC / 1000) << " ms" << std::endl;
  std::getchar();
  return 0;
}