#include <bits/stdc++.h>
using namespace std;

class Solution {
  using Node = vector<int>;

 public:
  vector<Node> kClosest(vector<Node>& points, int k) {
    auto CompareRule = [&](const Node& A, const Node& B) {
      return A[0] * A[0] + A[1] * A[1] < B[0] * B[0] + B[1] * B[1];
    };
    priority_queue<Node, vector<Node>, decltype(CompareRule)> PQ(CompareRule);
    for (auto& i : points) {
      if (PQ.size() < k) {
        PQ.push(move(i));
      } else {
        if (CompareRule(i, PQ.top())) {
          PQ.pop();
          PQ.push(move(i));
        }
      }
    }
    points.clear();
    while (!PQ.empty()) {
      points.push_back(move(PQ.top()));
      PQ.pop();
    }
    return points;
  }
};

#if 0  // std::sort
class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    sort(points.begin(), points.end(), [&](const vector<int> &A, const vector<int> &B) {
      return A[0] * A[0] + A[1] * A[1] < B[0] * B[0] + B[1] * B[1];
    });
    return vector<vector<int>>(points.begin(), points.begin() + k);
  }
};
#endif
