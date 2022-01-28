#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class WordDictionary {
  enum { NumAlphabet = 26 };

  struct TrieNode {
    bool isWord;
    TrieNode** Children;

    TrieNode() noexcept : isWord(false) {
      Children = new TrieNode*[WordDictionary::NumAlphabet]();
    }
    ~TrieNode() noexcept {
      for (int i = 0; i < WordDictionary::NumAlphabet; ++i) delete Children[i];
      delete[] Children;
    }
  };

  TrieNode* __TrieRoot;

  inline bool MatchWord(string_view word, TrieNode* iTR, int i) noexcept {
    if (iTR == nullptr) return false;
    auto n = word.size();
    if (i == n) return iTR->isWord;
    const auto& c = word[i] - 'a';
    if (word[i] != '.')
      return MatchWord(word, iTR->Children[c], i + 1);
    else {
      for (int iX = 0; iX < WordDictionary::NumAlphabet; ++iX) {
        if (MatchWord(word, iTR->Children[iX], i + 1) == true) return true;
      }
    }
    return false;
  }

 public:
  WordDictionary() noexcept { __TrieRoot = new TrieNode(); }
  ~WordDictionary() noexcept { delete __TrieRoot; }

  inline void addWord(string_view word) noexcept {
    auto iTR = __TrieRoot;
    auto n = word.size();
    for (decltype(n) i = 0; i < n; ++i) {
      const auto& c = word[i] - 'a';
      if (iTR->Children[c] == nullptr) {
        iTR->Children[c] = new TrieNode();
      }
      iTR = iTR->Children[c];
    }
    iTR->isWord = true;
  }

  inline bool search(string_view word) noexcept {
    auto iTR = __TrieRoot;
    auto n = word.size();
    for (decltype(n) i = 0; i < n; ++i) {
      if (word[i] == '.') return MatchWord(word, iTR, i);
      const auto& c = word[i] - 'a';
      if (iTR == nullptr) return false;
      if (iTR->Children[c] == nullptr) return false;
      iTR = iTR->Children[c];
    }
    return iTR->isWord;
  }
};
