#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  // Initution is to Compute the cost of sending every person to City A and also
  // calculating the diff of both cities, & Now pick N persons which has least
  // diff and send them to City B
  static int twoCitySchedCost(vector<vector<int>>& costs) noexcept {
    // Variable Initialization
    int minCost = 0;

    // Compute the Cost to Send Everyone to City A
    for (const auto& i : costs) minCost += i[0];

    // Find the Difference Between City A & B, Sorting the Input Array
    sort(costs.begin(), costs.end(), [](const auto& A, const auto& B) {
      return A[0] - A[1] > B[0] - B[1];
    });

    // Subtract the Cost Difference
    for (int i = 0, __END = costs.size() / 2; i < __END; ++i)
      minCost = minCost - costs[i][0] + costs[i][1];

    // Runtime O(N)
    // Space O(1)
    return minCost;
  }
};
