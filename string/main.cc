#include "string.h"

#include <string>
#include <vector>
#include <iostream>

int main() {
  std::vector<std::string> words = { "catch", "me", "if", "you", "can" };
  std::cout << qingpei::toolkit::string::join(words, "~~") << "\n";
  std::cout << qingpei::toolkit::string::join(words, ',') << "\n";
  return 0;
}