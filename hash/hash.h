#ifndef QINGPEI_TOOLKIT_HASH_
#define QINGPEI_TOOLKIT_HASH_
extern "C" {
#include "md5.h"
}
#pragma warning(push, 0)
#include <string>
#pragma warning(pop)

namespace qingpei {
namespace toolkit {
namespace hash {

/**
  @brief      Compute MD5 digest of input bytes

  @param[in]  bytes data in byte-array form
  @param[in]  size  number of bytes to hash
  @param[out] digest  the computed 16-byte (128-bit) digest
*/
void md5(unsigned char* bytes, unsigned long size, unsigned char* digest);

std::string md5(unsigned char* bytes, unsigned long size);

} // namespace hash
} // namespace toolkit
} // namespace qingpei
#endif // QINGPEI_TOOLKIT_HASH_
