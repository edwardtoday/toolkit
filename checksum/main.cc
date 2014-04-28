#include "crc.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>

int main() {
  // test crc8
  uint8_t str[] = {0x61, 0x62, 0x63};
  uint8_t sum = qingpei::toolkit::checksum::bytesum(str, 3);
  assert(sum == 0x26);
  // test crc16
  srand(static_cast<unsigned int>(time(NULL)));
  uint8_t testdata[1000];

  for (int i = 0; i < 10000; ++i) {
    for (int i = 0; i < 1000; ++i) {
      testdata[i] = rand() % 256;
    }

    uint16_t crc16 = qingpei::toolkit::checksum::crc16(testdata, 10);
    uint16_t crc16_lc300 = qingpei::toolkit::checksum::crc16_lc300(testdata, 10);
    assert(crc16 == crc16_lc300);
  }

  return 0;
}