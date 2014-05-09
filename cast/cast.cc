#include "cast.h"

namespace qingpei {
namespace toolkit {
namespace cast {
std::string array_to_bitset_string(const uint8_t* array, std::size_t length) {
  std::stringstream ss;

  for (std::size_t i = 0; i < length; ++i) {
    std::bitset<8> bit_for_byte(*(array + i));
    ss << bit_for_byte.to_string();
  }

  return ss.str();
}

} // namespace cast
} // namespace toolkit
} // namespace qingpei