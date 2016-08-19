#include <string>
#include <sstream>
#include <iomanip>

namespace qingpei {
namespace toolkit {
namespace string {

bool end_with(std::string const& fullString, std::string const& ending) {
  if (fullString.length() >= ending.length()) {
    return (0 == fullString.compare(fullString.length() - ending.length(),
                                    ending.length(), ending));
  } else {
    return false;
  }
}

std::string tail(std::string const& source, size_t const length) {
  if (length == source.size()) { return source; }

  if (length > source.size()) {
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(length) << source;
    return ss.str();
  }

  return source.substr(source.size() - length);
} // tail

} // namespace string
} // namespace toolkit
} // namespace qingpei