#include "cast.h"
#include "assert.h"

int main() {
  uint8_t bytes[] = {0x00, 0x0a, 0x01, 0x02};
  assert(0x0a == qingpei::toolkit::cast::bytes_to_uint16(bytes));
  assert(0x0a0102 == qingpei::toolkit::cast::bytes_to_uint32(bytes));
  return 0;
}