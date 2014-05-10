#include "crc.h"

#pragma warning(push, 0)
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(pop)

int main() {
  // test crc8
  uint8_t str[] = {0x61, 0x62, 0x63};
  uint8_t sum = qingpei::toolkit::checksum::bytesum(str, 3);
  assert(sum == 0x26);
  // test crc16
  uint8_t s[] = { 0x00, 0x34, 0x36, 0x30, 0x30, 0x32, 0x30, 0x38, 0x32, 0x32, 0x34, 0x38, 0x35, 0x34, 0x32, 0x30, 0x00, 0x18, 0x71, 0x41, 0xC3 };
  assert(0x6184 == qingpei::toolkit::checksum::crc16(s, 21));
  // test crc16 == crc16_lc300
  srand(static_cast<unsigned int>(time(NULL)));
  uint8_t testdata[1000];

  for (int i = 0; i < 1000; ++i) {
    for (int i = 0; i < 1000; ++i) {
      testdata[i] = static_cast<uint8_t>(rand() % 256);
    }

    uint16_t crc16 = qingpei::toolkit::checksum::crc16(testdata, 10);
    uint16_t crc16_lc300 = qingpei::toolkit::checksum::crc16_lc300(testdata, 10);
    assert(crc16 == crc16_lc300);
  }

  return 0;
}