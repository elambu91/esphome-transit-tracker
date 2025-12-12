#include "string_utils.h"
#include <sstream>
#include <algorithm>
#include <vector>

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
  std::vector<std::string> chars;
  size_t i = 0;
  
  while (i < s.length()) {
    unsigned char c = s[i];
    size_t char_len = 1;
    
    if ((c & 0x80) == 0) {
      char_len = 1;
    } else if ((c & 0xE0) == 0xC0) {
      char_len = 2;
    } else if ((c & 0xF0) == 0xE0) {
      char_len = 3;
    } else if ((c & 0xF8) == 0xF0) {
      char_len = 4;
    }
    
    if (i + char_len <= s.length()) {
      chars.push_back(s.substr(i, char_len));
    }
    
    i += char_len;
  }
  
  std::reverse(chars.begin(), chars.end());
  
  std::string result;
  for (const auto &ch : chars) {
    result += ch;
  }
  
  return result;
}