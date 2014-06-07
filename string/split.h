#ifndef QINGPEI_TOOLKIT_STRING_SPLIT_
#define QINGPEI_TOOLKIT_STRING_SPLIT_

#pragma warning(push, 0)
#include <vector>
#include <bitset>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#pragma warning(pop)

namespace qingpei {
namespace toolkit {
namespace string {

/************************************************************************/
/* String split functions. See http://stackoverflow.com/a/5506223                                                                     */
/************************************************************************/
template<typename C>
void split_custom(std::string const& s, char const* d, C& ret) {
  C output;
  std::bitset<255> delims;

  while (*d) {
    unsigned char code = *d++;
    delims[code] = true;
  }

  typedef std::string::const_iterator iter;
  iter beg;
  bool in_token = false;

  for (std::string::const_iterator it = s.begin(), end = s.end();
       it != end; ++it) {
    if (delims[*it]) {
      if (in_token) {
        output.push_back(typename C::value_type(beg, it));
        in_token = false;
      }
    } else if (!in_token) {
      beg = it;
      in_token = true;
    }
  }

  if (in_token) {
    output.push_back(typename C::value_type(beg, s.end()));
  }

  output.swap(ret);
}

template<typename C>
void split_strpbrk(std::string const& s, char const* delims, C& ret) {
  C output;
  char const* p = s.c_str();
  char const* q = strpbrk(p + 1, delims);

  for (; q != NULL; q = strpbrk(p, delims)) {
    output.push_back(typename C::value_type(p, q));
    p = q + 1;
  }

  output.swap(ret);
}

template<typename C>
void split_boost(std::string const& s, char const* delims, C& ret) {
  C output;
  boost::split(output, s, boost::is_any_of(delims));
  output.swap(ret);
}

} // namespace string
} // namespace toolkit
} // namespace qingpei
#endif // QINGPEI_TOOLKIT_STRING_SPLIT_