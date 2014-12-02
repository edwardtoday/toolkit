#include "string.h"

#pragma warning(push, 0)
#include <string>
#include <vector>
#include <iostream>
#include <boost/timer.hpp>
#include <memory>
#pragma warning(pop)

int main() {
  std::vector<std::string> words = { "catch", "me", "if", "you", "can" };
  std::cout << qingpei::toolkit::string::join(words, "~~") << "\n";
  std::cout << qingpei::toolkit::string::join(words, ',') << "\n";
  size_t const N = 1000000;
  // Generate random text
  std::unique_ptr<std::string> text(new std::string(N, ' '));

  for (size_t i = 0; i != N; ++i) {
    (*text)[i] = (i % 2 == 0) ? ('a' + (i / 2) % 26) : ((i / 2) % 2 ? ' ' : '\t');
  }

  char const* delims = ",\t";
  // Output strings
  boost::timer timer;
  std::vector<std::string> vsb;
  qingpei::toolkit::string::split_boost(*text, delims, vsb);
  std::cout << "Time boost: " << timer.elapsed() << std::endl;
  // Output string views
  typedef std::string::const_iterator iter;
  typedef boost::iterator_range<iter> string_view;
  timer.restart();
  std::vector<string_view> vsvb;
  qingpei::toolkit::string::split_boost(*text, delims, vsvb);
  std::cout << "Time boost view: " << timer.elapsed() << std::endl;
  // Custom split
  timer.restart();
  std::vector<std::string> vs;
  qingpei::toolkit::string::split_custom(*text, delims, vs);
  std::cout << "Time custom: " << timer.elapsed() << std::endl;
  // Custom split views
  timer.restart();
  std::vector<string_view> vsv;
  qingpei::toolkit::string::split_custom(*text, delims, vsv);
  std::cout << "Time custom view: " << timer.elapsed() << std::endl;
  // Custom split strpbrk
  timer.restart();
  std::vector<std::string> vsp;
  qingpei::toolkit::string::split_strpbrk(*text, delims, vsp);
  std::cout << "Time strpbrk: " << timer.elapsed() << std::endl;
  return 0;
}