#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
  unordered_map<string, string> mapping;

 public:
  // Encodes a URL to a shortened URL.
  string encode(const string& longURL) noexcept {
    static string hashURL = "000000";
    static const string tinyURL = "http://tinyurl.com/";

    for (int i = hashURL.size() - 1; i >= 0; --i) {
      bool carry = false;
      switch (hashURL[i]) {
        case 57:
          hashURL[i] = 64;
          carry = true;
          break;
        case 90:
          hashURL[i] = 96;
          carry = true;
          break;
        case 122:
          hashURL[i] = 47;
          carry = true;
          break;
      }
      ++hashURL[i];
      if (!carry) break;
    }

    mapping[hashURL] = longURL;

    return tinyURL + hashURL;
  }

  // Decodes a shortened URL to its original URL.
  string decode(const string& shortURL) noexcept {
    return mapping[shortURL.substr(shortURL.size() - 6, 6)];
  }
};
