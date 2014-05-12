#include "cast.h"
#include <ctype.h>

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

std::string hex_string_to_bitset_string(const std::string& hex_string) {
  std::string binary_string = "";

  for (int i = 0; i < hex_string.length(); ++i) {
    switch (tolower(hex_string[i])) {
    case '0':
      binary_string.append("0000");
      break;

    case '1':
      binary_string.append("0001");
      break;

    case '2':
      binary_string.append("0010");
      break;

    case '3':
      binary_string.append("0011");
      break;

    case '4':
      binary_string.append("0100");
      break;

    case '5':
      binary_string.append("0101");
      break;

    case '6':
      binary_string.append("0110");
      break;

    case '7':
      binary_string.append("0111");
      break;

    case '8':
      binary_string.append("1000");
      break;

    case '9':
      binary_string.append("1001");
      break;

    case 'a':
      binary_string.append("1010");
      break;

    case 'b':
      binary_string.append("1011");
      break;

    case 'c':
      binary_string.append("1100");
      break;

    case 'd':
      binary_string.append("1101");
      break;

    case 'e':
      binary_string.append("1110");
      break;

    case 'f':
      binary_string.append("1111");
      break;
    }
  }

  return binary_string;
}

} // namespace cast
} // namespace toolkit
} // namespace qingpei