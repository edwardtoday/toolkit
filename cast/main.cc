#include "cast.h"
#pragma warning(push, 0)
#include "assert.h"
#include <iostream>
#pragma warning(pop)

int main() {
  uint8_t bytes[] = {0x00, 0x0a, 0x01, 0x02};
  assert(0x0a == qingpei::toolkit::cast::bytes_to_num<uint16_t>(bytes));
  assert(0x0a0102 == qingpei::toolkit::cast::bytes_to_num<uint32_t>(bytes));
  std::cout << qingpei::toolkit::cast::array_to_hex_string(bytes, 4) << "\n";
  uint8_t byte_num = 0x02;
  std::cout << qingpei::toolkit::cast::num_to_hex_string(byte_num) << "\n";
  int8_t int8_num = 0xf1;
  std::cout << qingpei::toolkit::cast::num_to_hex_string(int8_num) << "\n";
  int16_t int16_num = 0x1122;
  std::cout << qingpei::toolkit::cast::num_to_hex_string(int16_num) << "\n";
  std::cout << qingpei::toolkit::cast::num_to_hex_string(0x11223344) << "\n";
  std::cout << qingpei::toolkit::cast::num_to_hex_string(
              0x1122334455667788) << "\n";
  std::cout << qingpei::toolkit::cast::array_to_bitset_string(bytes, 4) << "\n";
  std::string hex_string("0A0B02");
  std::cout << qingpei::toolkit::cast::hex_string_to_bitset_string(hex_string);
  return 0;
}