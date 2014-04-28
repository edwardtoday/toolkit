#ifndef QINGPEI_TOOLKIT_CAST_
#define QINGPEI_TOOLKIT_CAST_

#include <stdint.h>

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
} // namespace cast
} // namespace toolkit
} // namespace qingpei
#endif // QINGPEI_TOOLKIT_CAST_
