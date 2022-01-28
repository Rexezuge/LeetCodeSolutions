#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

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
   * Path Compression Optimization
   * Find the Root of Any Vertex
   */
  uint Find(uint Val) noexcept {
    if (Val == __Set[Val]) return Val;
    return __Set[Val] = Find(__Set[Val]);
  }

  /**
   * Union by Rank Optimization
   * Connect Any Two Vertices
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

  bool isConnected(uint A, uint B) noexcept { return Find(A) == Find(B); }

  uint getCount() const noexcept { return __Count; }
};

class Solution {
 public:
  int findCircleNum(const vector<vector<int>>& isConnected) noexcept {
    const uint n = isConnected.size();
    DisjointSet* DS = new DisjointSet(n);
    for (uint iX = 0; iX < n; ++iX)
      for (uint iY = 0; iY < n; ++iY)
        if (isConnected[iX][iY] == 1) DS->Union(iX, iY);
    return DS->getCount();
  }
};
