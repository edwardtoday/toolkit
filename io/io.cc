#include "io.h"
#pragma warning(push, 0)
#include <string>
#include <fstream>
#pragma warning(pop)

namespace qingpei {
namespace toolkit {
namespace io {

std::string read_file_as_string(const char* filename) {
  // from http://stackoverflow.com/q/2602013
  std::ifstream in(filename, std::ios::in | std::ios::binary);

  if (in) {
    std::string contents;
    in.seekg(0, std::ios::end);
    contents.resize(static_cast<unsigned int>(in.tellg()));
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