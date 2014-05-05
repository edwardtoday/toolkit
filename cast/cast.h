#ifndef QINGPEI_TOOLKIT_CAST_
#define QINGPEI_TOOLKIT_CAST_

#include <stdint.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

namespace qingpei {
namespace toolkit {
namespace cast {
/* Conversions between bytes (uint8_t) and integer types
   Caller should make sure
     - input pointer is valid
     - output pointer has enough space allocated
 **/
uint16_t bytes_to_uint16(const uint8_t* bytes);

void uint16_to_bytes(uint16_t num, uint8_t* bytes);

uint32_t bytes_to_uint32(const uint8_t* bytes);

void uint32_to_bytes(uint32_t num, uint8_t* bytes);

/* Convert array to hex string
   e.g. {0x11, 0x02, 0x33} => "110233"
 **/
template<class T>
std::string array_to_hex_string(const T* array, std::size_t length) {
  std::stringstream ss;
  const std::size_t width = sizeof(array[0]) * 2;

  for (std::size_t i = 0; i < length; ++i) {
    ss << std::hex << std::setfill('0') << std::uppercase << std::setw(width) <<
       (int)(array[i]);
  }

  return ss.str();
}

/* Convert vector to string
  e.g. {a, b, c} => "[a,b,c,]"
  Notice that last comma.
**/
template<class T>
std::string vector_to_string(const std::vector<T> vec) {
  std::stringstream ss;
  ss << "[";

  for (T i : vec) {
    ss << i << ",";
  }

  ss << "]";
  return ss.str();
}

template<class T>
std::string num_to_hex_string(const T num) {
  std::stringstream ss;
  const std::size_t width = sizeof(num) * 2;
  ss << std::hex << std::setfill('0') << std::uppercase << std::setw(
       width) << (int)num;
  return ss.str();
}

} // namespace cast
} // namespace toolkit
} // namespace qingpei
#endif // QINGPEI_TOOLKIT_CAST_
