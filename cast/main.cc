#include "cast.h"
#include "assert.h"

int main() {
  uint8_t num15[] = {0x00, 0x0a};
  assert(0x0a == qingpei::toolkit::cast::bytes_to_uint16(num15));
  return 0;
}