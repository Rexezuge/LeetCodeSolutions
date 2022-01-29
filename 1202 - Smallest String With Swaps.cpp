#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
  class DisjointSet {
    const uint __Size;
    uint __Count;
    uint* __Set;
    uint* __Rank;

   public:
    explicit DisjointSet(uint n) noexcept : __Size(n), __Count(n) {
      __Set = new uint[__Size];
      __Rank = new uint[__Size];
      for (uint i = 0; i < __Size; ++i) __Set[i] = i, __Rank[i] = 1;
    }

    ~DisjointSet() noexcept {
      delete[] __Set;
      delete[] __Rank;
    }

    /**
     * Find the Root of Any Vertex
     * Path Compression Optimization - ON
     */
    uint Find(uint Val) noexcept {
      if (Val == __Set[Val]) return Val;
      return __Set[Val] = Find(__Set[Val]);
    }

    /**
     * Find the Root of Any Vertex
     * Path Compression Optimization - OFF
     */
    uint Find(uint Val) const noexcept {
      while (Val != __Set[Val]) Val = __Set[Val];
      return Val;
    }

    /**
     * Connect Any Two Vertices
     * Union by Rank Optimization - ON
     */
    void Union(uint A, uint B) noexcept {
      const auto A_Root = Find(A);
      const auto B_Root = Find(B);
      if (A_Root == B_Root) return;
      if (__Rank[A_Root] > __Rank[B_Root]) {
        __Set[B_Root] = A_Root;
      } else if (__Rank[A_Root] < __Rank[B_Root]) {
        __Set[A_Root] = B_Root;
      } else {
        __Set[B_Root] = A_Root;
        ++__Rank[A_Root];
      }
      --__Count;
    }

    /**
     * Connect Any Two Vertices
     * Union by Rank Optimization - OFF
     */
    void Union(uint A, uint B, bool Opt) = delete;
#if 0
    {
      const auto A_Root = Find(A);
      const auto B_Root = Find(B);
      if (A_Root == B_Root) return;
      __Set[B_Root] = A_Root;
      --__Count;
    }
#endif

    /**
     * Check if Two Vertices Are Connected
     */
    bool isConnected(uint A, uint B) noexcept { return Find(A) == Find(B); }

    /**
     * Check if Two Vertices Are Connected
     */
    bool isConnected(uint A, uint B) const noexcept {
      return Find(A) == Find(B);
    }

    /**
     * Get Number of Different Groups
     */
    uint getCount() const noexcept { return __Count; }
  };

 public:
  string smallestStringWithSwaps(
      const string& s, const vector<vector<int>>& pairs) const noexcept {
    string Result = s;
    int n = s.size();
    DisjointSet DS(n);

    for (const auto& i : pairs) DS.Union(i[0], i[1]);

    vector<vector<int>> Index(n);
    vector<string> Buffer(n);
    for (int i = 0; i < n; ++i) {
      int Root = DS.Find(i);
      Index[Root].push_back(i);  // Already Sorted
      Buffer[Root].push_back(s[i]);
    }

    for (int iX = 0; iX < n; ++iX) {
      sort(Buffer[iX].begin(), Buffer[iX].end());
      for (int iY = 0; iY < Index[iX].size(); ++iY)
        Result[Index[iX][iY]] = Buffer[iX][iY];
    }

    return Result;
  }
};

#if 0  // Works, Using DFS
class Solution {
 public:
  string smallestStringWithSwaps(
      const string& s, const vector<vector<int>>& pairs) const noexcept {
    string Result = s;
    vector<vector<int>> Graph(s.size());
    unordered_set<int> Visited;
    vector<int> Index;
    string Buffer;

    for (const auto& i : pairs)
      Graph[i[0]].push_back(i[1]), Graph[i[1]].push_back(i[0]);

    function<void(int)> DFS = [&](int Position) {
      if (Visited.count(Position) > 0) return;
      Visited.insert(Position);
      Index.push_back(Position);
      Buffer.push_back(s[Position]);
      for (const auto i : Graph[Position]) DFS(i);
    };

    for (int i = 0; i < s.size(); ++i) {
      if (Visited.count(i) > 0) continue;
      Index.clear();
      Buffer.clear();
      DFS(i);
      sort(Index.begin(), Index.end());
      sort(Buffer.begin(), Buffer.end());
      for (int i = 0; i < Index.size(); ++i) Result[Index[i]] = Buffer[i];
    }

    return Result;
  }
};
#endif
