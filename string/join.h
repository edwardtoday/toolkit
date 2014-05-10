#ifndef QINGPEI_TOOLKIT_STRING_JOIN_
#define QINGPEI_TOOLKIT_STRING_JOIN_

#pragma warning(push, 0)
#include <string>
#include <sstream>
#pragma warning(pop)

namespace qingpei {
namespace toolkit {
namespace string {

template <typename T>
std::string join(const T& v, const std::string& delim) {
  std::stringstream s;

  for (const auto& i : v) {
    if (&i != &v[0]) {
      s << delim;
    }

    s << i;
  }

  return s.str();
}

template <typename T>
std::string join(const T& v, const char delim) {
  return join(v, std::string(1, delim));
}

} // namespace string
} // namespace toolkit
} // namespace qingpei
#endif // QINGPEI_TOOLKIT_STRING_JOIN_