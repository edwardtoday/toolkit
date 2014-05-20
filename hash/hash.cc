#include "hash.h"
#include "../cast/cast.h"

namespace qingpei {
namespace toolkit {
namespace hash {

void md5(unsigned char* bytes, unsigned long size, unsigned char* digest) {
  MD5_CTX ctx;
  MD5_Init(&ctx);
  MD5_Update(&ctx, bytes, size);
  MD5_Final(digest, &ctx);
}

std::string md5(unsigned char* bytes, unsigned long size) {
  unsigned char digest[16];
  md5(bytes, size, digest);
  return qingpei::toolkit::cast::array_to_hex_string(digest, 16);
}
} // namespace hash
} // namespace toolkit
} // namespace qingpei