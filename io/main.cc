#include "io.h"
#include <iostream>

int main() {
  std::cout << qingpei::toolkit::io::read_file_as_string("main.cc");
  return 0;
}