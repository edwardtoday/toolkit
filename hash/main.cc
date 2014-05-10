#include "hash.h"

#pragma warning(push, 0)
#include <string>
#include <iostream>
#pragma warning(pop)

int main() {
  char str[] = "qingpei";
  std::cout  << qingpei::toolkit::hash::md5((unsigned char*)str, strlen(str));
  // digest should be 4c8640bc1bd6fbb68efa09407806e77a
  return 0;
}