#include "io.h"
#pragma warning(push, 0)
#include <iostream>
#pragma warning(pop)

int main() {
  std::cout << qingpei::toolkit::io::read_file_as_string("main.cc");
  return 0;
}