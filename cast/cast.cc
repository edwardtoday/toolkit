#include "cast.h"

namespace qingpei {
namespace toolkit {
namespace cast {
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
} // namespace cast
} // namespace toolkit
} // namespace qingpei