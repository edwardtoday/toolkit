#include "random.h"
#include <random>

namespace qingpei {
namespace toolkit {
namespace random {

std::random_device rd; // obtain a random number from hardware
std::mt19937 eng(rd()); // seed the generator

int random_in_range(int min, int max) {
  std::uniform_int_distribution<> distr(min, max); // define the range
  return distr(eng);
}

} // namespace random
} // namespace toolkit
} // namespace qingpei