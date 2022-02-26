#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

/*
Intuition

The previous approach is comparatively slow but works because the bounds are
small. The main problem is that we are working backwards and need a DFS starting
from every node. The optimal path may end at node 0, but we still need to check
all other nodes to make sure. As with any problem that asks us to find the
shortest path, it may be more intuitive to approach this problem using BFS.

Because BFS guarantees the shortest path in an unweighted graph, as soon as we
find an answer, we know it is the optimal one, unlike in the previous solution
where we needed to explore all reachable states to make sure.

This approach is similar to the previous one in terms of logic. However, instead
of using top-down dynamic programming in the form of DFS + memoization, we will
perform BFS by implementing a queue. Instead of starting at endingMask, we will
start at the base case masks - only having one bit set to 1, and then work our
way towards endingMask.

Because we were working backwards in the previous approach, for all neighbors,
we needed to check (neighbor, mask) and (neighbor, mask ^ (1 << node)). Now,
since we're moving forwards, the state we should consider next from each (node,
mask) is different. If we are at node A and move to node B, it doesn't matter if
we go B -> A -> B or A -> B - in both cases, upon arriving at B, we want our
mask to have the bit corresponding to node B set as 1. This is a nice
improvement on the previous approach as for each neighbor, we only need to
consider 1 possibility instead of 2. Since we always want the bit to be set to
1, we will use an OR operation with 1 << neighbor to make sure the bit is set
to 1.

More formally, for any given state (node, mask), we can traverse to (neighbor,
mask | (1 << neighbor)) for all neighbors in graph[node]. We will still need to
use some space to ensure that we don't revisit states and create an infinite
cycle, but this time we don't need to associate the states with any values, just
a flag to indicate if it has been visited yet or not.

Algorithm

If graph only contains one node, then return 0 as we can start at node 0 and
complete the problem without taking any steps.

Initialize some variables:

n, as the length of graph.
endingMask = (1 << n) - 1, a bitmask that represents all nodes being visited.
seen, a data structure that will be used to indicate if we have visited a state
to prevent cycles. queue, a data structure that implements an abstract queue
used for our BFS. steps, an integer that keeps track of which step we are on.
Since BFS gaurantees a shortest path, as soon as we encounter endingMask, we can
return steps. Populate queue and seen with the base cases (starting at all nodes
with the mask set to having only visited the given node). This is (i, 1 << i)
for all i from 0 to n - 1.

Perform a BFS:

Initialize nextQueue, which will replace queue at the end of the current step.
Loop through the current queue. For each state (node, mask), loop through
graph[node]. For each neighbor, declare a new state (neighbor, nextMask), where
nextMask = mask | (1 << neighbor). If nextMask == endingMask, then that means
taking one more step to the neighbor will complete visiting all nodes, so return
1 + steps. Otherwise, if this new state has not yet been visited, then add it
nextQueue and seen. After looping through the current queue, increment steps by
1 and replace queue with nextQueue. The constraints state that the input graph
is always connected, therefore there will always be an answer. The return
statement in the BFS will always trigger, and we don't need to worry about other
cases.
*/

class Solution {
 public:
  static int shortestPathLength(const vector<vector<int>>& graph) noexcept {
    // Edge Case
    if (graph.size() == 1) return 0;

    // Initialization
    const int n = graph.size(), endingMask = (1 << n) - 1;
    vector<vector<bool>> isSeen(n, vector<bool>(endingMask, false));
    queue<pair<int, int>> currentQueue;

    // Initialize the Queue
    for (int i = 0; i < n; ++i)
      currentQueue.push({i, 1 << i}), isSeen[i][1 << i] = true;

    // Perform BFS Algorithm
    int stepCounter = 0;
    while (!currentQueue.empty()) {
      queue<pair<int, int>> nextQueue;
      while (!currentQueue.empty()) {
        auto [node, mask] = currentQueue.front();
        for (int neighbor : graph[node]) {
          int nextMask = mask | (1 << neighbor);
          if (nextMask == endingMask) return stepCounter + 1;
          if (!isSeen[neighbor][nextMask])
            isSeen[neighbor][nextMask] = true,
            nextQueue.push({neighbor, nextMask});
        }
        currentQueue.pop();
      }
      ++stepCounter;
      currentQueue = move(nextQueue);
    }

    // On Error
    return -1;
  }
};
