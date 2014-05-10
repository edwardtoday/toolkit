#include "string.h"

#pragma warning(push, 0)
#include <string>
#include <vector>
#include <iostream>
#pragma warning(pop)

int main() {
  std::vector<std::string> words = { "catch", "me", "if", "you", "can" };
  std::cout << qingpei::toolkit::string::join(words, "~~") << "\n";
  std::cout << qingpei::toolkit::string::join(words, ',') << "\n";
  return 0;
}