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
    uint Find(uint Val) {
      if (Val >= __Size)
        throw out_of_range("DisjointSet::Find(): Index Out of Range");
      if (Val == __Set[Val]) return Val;
      return __Set[Val] = Find(__Set[Val]);
    }

    /**
     * Find the Root of Any Vertex
     * Path Compression Optimization - OFF
     */
    uint Find(uint Val) const {
      if (Val >= __Size)
        throw out_of_range("DisjointSet::Find(): Index Out of Range");
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

#if 0
    /**
     * Connect Any Two Vertices
     * Union by Rank Optimization - OFF
     */
    void Union(uint A, uint B) noexcept {
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

  using Node = vector<int>;

 public:
  const int minCostConnectPoints(vector<vector<int>>& points) noexcept {
    auto minHeap_Comp = [&](const Node& A, const Node& B) {
      return A[2] > B[2];
    };

    priority_queue<Node, vector<Node>, decltype(minHeap_Comp)> minHeap(
        minHeap_Comp);

    auto CalcDistance = [&](const int A, const int B) {
      if (A != B)
        minHeap.push({A, B,
                      abs(points[A][0] - points[B][0]) +
                          abs(points[A][1] - points[B][1])});
    };

    const int n = points.size();
    for (int iX = 0; iX < n; ++iX)
      for (int iY = 0; iY < n; ++iY) CalcDistance(iX, iY);

    uint Edges = 0, Sum = 0;
    DisjointSet DS(n);

    while (!minHeap.empty()) {
      const auto& i = minHeap.top();
      if (!DS.isConnected(i[0], i[1])) {
        ++Edges;
        Sum += i[2];
        DS.Union(i[0], i[1]);
      }
      if (Edges == n - 1) return Sum;
      minHeap.pop();
    }

    return 0;
  }
};
