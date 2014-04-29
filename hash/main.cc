#include "hash.h"
#include <string>
#include <iostream>

int main() {
  char str[] = "qingpei";
  std::cout  << qingpei::toolkit::hash::md5((unsigned char*)str, strlen(str));
  // digest should be 4c8640bc1bd6fbb68efa09407806e77a
  return 0;
}