#include "string_utils.h"
#include <sstream>
#include <algorithm>

std::vector<std::string> split(const std::string &s, char delim) {
  std::vector<std::string> elems;
  std::stringstream ss(s);
  std::string item;
  while (std::getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}

std::string reverse_string(const std::string &s) {
  std::string result = s;
  std::reverse(result.begin(), result.end());
  return result;
}