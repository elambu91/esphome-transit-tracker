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

std::string reverse_hebrew_only(const std::string &s) {
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
  
  std::vector<std::string> hebrew_chars;
  std::vector<std::string> non_hebrew_chars;
  std::vector<bool> is_hebrew_pos;
  
  for (const auto &ch : chars) {
    if (ch.length() >= 2) {
      unsigned char first = ch[0];
      unsigned char second = ch[1];
      if (first == 0xD7 && second >= 0x90 && second <= 0xBF) {
        hebrew_chars.push_back(ch);
        is_hebrew_pos.push_back(true);
        continue;
      } else if (first == 0xD6 && second >= 0x80) {
        hebrew_chars.push_back(ch);
        is_hebrew_pos.push_back(true);
        continue;
      }
    }
    non_hebrew_chars.push_back(ch);
    is_hebrew_pos.push_back(false);
  }
  
  std::reverse(hebrew_chars.begin(), hebrew_chars.end());
  
  std::string result;
  size_t heb_idx = 0;
  size_t non_heb_idx = 0;
  
  for (bool is_heb : is_hebrew_pos) {
    if (is_heb) {
      result += hebrew_chars[heb_idx++];
    } else {
      result += non_hebrew_chars[non_heb_idx++];
    }
  }
  
  return result;
}