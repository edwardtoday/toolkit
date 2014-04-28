#ifndef QINGPEI_TOOLKIT_CAST_
#define QINGPEI_TOOLKIT_CAST_

#include <stdint.h>
#include <string>
#include <sstream>
#include <iomanip>

namespace qingpei {
namespace toolkit {
namespace cast {
/* Conversions between bytes (uint8_t) and integer types
   Caller should make sure
     - input pointer is valid
     - output pointer has enough space allocated
 **/
uint16_t bytes_to_uint16(const uint8_t* bytes) {
  return static_cast<uint16_t>(bytes[0] << 8 | bytes[1]);
}

void uint16_to_bytes(uint16_t num, uint8_t* bytes) {
  bytes[0] = static_cast<uint8_t>((num >> 8) & 0xff);
  bytes[1] = static_cast<uint8_t>(num & 0xff);
}

uint32_t bytes_to_uint32(const uint8_t* bytes) {
  return static_cast<uint32_t>(
           bytes[0] << 24 |
           bytes[1] << 16 |
           bytes[2] << 8 |
           bytes[3]);
}

void uint32_to_bytes(uint32_t num, uint8_t* bytes) {
  bytes[0] = static_cast<uint8_t>((num >> 24) & 0xff);
  bytes[1] = static_cast<uint8_t>((num >> 16) & 0xff);
  bytes[2] = static_cast<uint8_t>((num >> 8) & 0xff);
  bytes[3] = static_cast<uint8_t>(num & 0xff);
}

/* Convert array to hex string
   e.g. {0x11, 0x02, 0x33} => "110233"
 **/
template<class T>
std::string array_to_hex_string(const T* array, std::size_t length) {
  std::stringstream ss;
  const std::size_t width = sizeof(array[0]) * 2;

  for (std::size_t i = 0; i < length; ++i) {
    ss << std::hex << std::setfill('0') << std::uppercase << std::setw(width) << (array[i]);
  }

  return ss.str();
}

template<class T>
std::string num_to_hex_string(const T num) {
  std::stringstream ss;
  const std::size_t width = sizeof(num) * 2;

  ss << std::hex << std::setfill('0') << std::uppercase << std::setw(width) << num;
  return ss.str();
}

} // namespace cast
} // namespace toolkit
} // namespace qingpei
#endif // QINGPEI_TOOLKIT_CAST_
