#include "io.hpp"

namespace qingpei {
namespace toolkit {
namespace io {

std::string read_file_as_string(const char* filename) {
  // from http://stackoverflow.com/q/2602013
  std::ifstream in(filename, std::ios::in | std::ios::binary);

  if (in) {
    std::string contents;
    in.seekg(0, std::ios::end);
    contents.resize(in.tellg());
    in.seekg(0, std::ios::beg);
    in.read(&contents[0], contents.size());
    in.close();
    return contents;
  }

  throw (errno);
}

} // namespace io
} // namespace toolkit
} // namespace qingpei