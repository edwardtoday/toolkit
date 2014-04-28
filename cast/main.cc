#include "cast.h"
#include "assert.h"

#include <iostream>

int main() {
  uint8_t bytes[] = {0x00, 0x0a, 0x01, 0x02};
  assert(0x0a == qingpei::toolkit::cast::bytes_to_uint16(bytes));
  assert(0x0a0102 == qingpei::toolkit::cast::bytes_to_uint32(bytes));
  std::cout << qingpei::toolkit::cast::bytes_to_hex_string(bytes, 4) << "\n";
  std::cout << qingpei::toolkit::cast::num_to_hex_string(0x1122) << "\n";
  std::cout << qingpei::toolkit::cast::num_to_hex_string(0x11223344) << "\n";
  std::cout << qingpei::toolkit::cast::num_to_hex_string(
              0x1122334455667788) << "\n";
  return 0;
}