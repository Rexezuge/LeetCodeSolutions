#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Trie {
  enum { NumAlphabet = 26 };

  struct TrieNode {
    bool isWord;
    TrieNode** Children;

    TrieNode() noexcept : isWord(false) {
      Children = new TrieNode*[Trie::NumAlphabet]();
    }
    ~TrieNode() noexcept {
      for (int i = 0; i < Trie::NumAlphabet; ++i) delete Children[i];
      delete[] Children;
    }
  };

  TrieNode* __TrieRoot;

 public:
  Trie() noexcept { __TrieRoot = new TrieNode(); }
  ~Trie() noexcept { delete __TrieRoot; }

  inline void insert(string_view word) noexcept {
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
      const auto& c = word[i] - 'a';
      if (iTR == nullptr) return false;
      if (iTR->Children[c] == nullptr) return false;
      iTR = iTR->Children[c];
    }
    return iTR->isWord;
  }

  inline bool startsWith(string_view prefix) noexcept {
    auto iTR = __TrieRoot;
    auto n = prefix.size();
    for (decltype(n) i = 0; i < n; ++i) {
      const auto& c = prefix[i] - 'a';
      if (iTR == nullptr) return false;
      if (iTR->Children[c] == nullptr) return false;
      iTR = iTR->Children[c];
    }
    return true;
  }
};

#if 0  // Main Function
int main(void) {
  Trie* TrieObj = new Trie();
  cout << boolalpha;

  TrieObj->insert("yahello");
  cout << "Expected: true,  Actual: " << TrieObj->search("yahello") << endl;
  cout << "Expected: false, Actual: " << TrieObj->search("yahelloi") << endl;
  cout << "Expected: false, Actual: " << TrieObj->search("yahelloiu") << endl;
  cout << "Expected: true,  Actual: " << TrieObj->startsWith("ya") << endl;
  cout << "Expected: false, Actual: " << TrieObj->startsWith("ay") << endl;

  delete TrieObj;
  return EXIT_SUCCESS;
}
#endif
