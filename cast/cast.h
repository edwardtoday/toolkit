#ifndef QINGPEI_TOOLKIT_CAST_
#define QINGPEI_TOOLKIT_CAST_


#include <stdint.h>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <bitset>


namespace qingpei {
namespace toolkit {
namespace cast {
/** Convert array to hex string
   e.g. {0x11, 0x02, 0x33} => "110233"
*/
template<class T>
std::string array_to_hex_string(const T* array, std::size_t length) {
  std::stringstream ss;
  std::size_t width = sizeof(array[0]) * 2;

  if (width < 3) {
    for (std::size_t i = 0; i < length; ++i) {
      ss << std::hex << std::setfill('0') << std::uppercase << std::setw(width) <<
         (int)(array[i]);
    }
  } else {
    for (std::size_t i = 0; i < length; ++i) {
      ss << std::hex << std::setfill('0') << std::uppercase << std::setw(width) <<
         array[i];
    }
  }

  return ss.str();
}

std::string array_to_bitset_string(const uint8_t* array, std::size_t length);

/** Convert vector to string
  e.g. {a, b, c} => "[a,b,c,]"
  Notice that last comma.
*/
template<class T>
std::string vector_to_string(const std::vector<T> vec) {
  std::stringstream ss;
  ss << "[";

  for (T i : vec) {
    ss << i << ",";
  }

  ss << "]";
  return ss.str();
}

/** Convert a numerical type to hex string
  e.g. (uint8_t)(12) => "0x0C", (int32_t)(4) => "0x00000004"
*/
template<class T>
std::string num_to_hex_string(const T num) {
  std::stringstream ss;
  std::size_t width = sizeof(num) * 2; // size in bytes

  if (width < 3) {
    /// artifacts, see http://blog.mezeske.com/?p=170
    ss << std::hex << std::setfill('0') << std::uppercase << std::setw(
         width) << static_cast<int>(num);
  } else {
    ss << std::hex << std::setfill('0') << std::uppercase << std::setw(
         width) << num;
  }

  return ss.str();
}

/**
  @brief    Conversions from integer types to bytes (uint8_t*)
  @warning  Caller should make sure that
              - input pointer is valid
              - output pointer has enough space (sizeof(num) bytes) allocated
*/
template<class T>
void num_to_bytes(const T num, uint8_t* bytes) {
  const std::size_t width = sizeof(num);  // size in bytes

  for (int i = 0; i < width; ++i) {
    bytes[width - 1 - i] = static_cast<uint8_t>(num >>(i * 8));
  }
}

template<class T>
T bytes_to_num(const uint8_t* bytes) {
  T result = 0;
  const std::size_t width = sizeof(result);  // size in bytes

  for (int i = 0; i < width; ++i) {
    result |= bytes[i] << ((width - i - 1) * 8);
  }

  return result;
}

std::string hex_string_to_bitset_string(const std::string& hex_string);

} // namespace cast
} // namespace toolkit
} // namespace qingpei
#endif // QINGPEI_TOOLKIT_CAST_
