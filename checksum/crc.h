#ifndef QINGPEI_TOOLKIT_CHECKSUM_
#define QINGPEI_TOOLKIT_CHECKSUM_

#include <cstdint>
#include <cstddef>

namespace qingpei {
namespace toolkit {
namespace checksum {

/**
  @brief Calculate byte-wise sum of an input buffer

  @param buffer input buffer
  @param buffer_length length of buffer in bytes

  @return checksum
*/
uint8_t bytesum(const uint8_t* buffer, std::size_t buffer_length);

/**
  @brief Calculate CRC checksum of an input buffer (Used in SkyEye)
         CCITT-16: 0x1021    x^16 + x^12 + x^5 + 1
  @param buffer input buffer
  @param buffer_length length of buffer in bytes

  @return CRC checksum
*/
uint16_t crc16(const uint8_t* buffer, std::size_t buffer_length);

/**
  @brief Calculate CRC checksum of an input buffer (Used in LC300)
         CCITT-16: 0x1021    x^16 + x^12 + x^5 + 1
  Prefer using crc16(). That implementation is more than 4X faster.

  @param buffer input buffer
  @param buffer_length length of buffer in bytes

  @return CRC checksum
*/
uint16_t crc16_lc300(const uint8_t* buffer, std::size_t buffer_length);

} // namespace checksum
} // namespace toolkit
} // namespace qingpei
#endif // QINGPEI_TOOLKIT_CHECKSUM_