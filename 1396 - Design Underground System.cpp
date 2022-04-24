#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class UndergroundSystem {
  // Travel Time Repersentation
  // unordered_map<startStation,
  //               unordered_map<endStation, pair<numTravels, totalTravelTime>>>
  unordered_map<string, unordered_map<string, pair<int, int>>> travelTime;

  // Current Traveling Customer Repersentation
  // unordered_map<ID, pair<startStation, startTime>>
  unordered_map<int, pair<string, int>> inTransit;

 public:
  UndergroundSystem() = default;

  void checkIn(int id, string startStation, int t) noexcept {
    if (inTransit.count(id) > 0)
      // Customer Already in Transit, Not Able to Check In Again
      return;

    // Check In Customer
    inTransit.insert({id, {startStation, t}});
  }

  void checkOut(int id, string endStation, int t) {
    if (inTransit.count(id) == 0)
      // Custimer Not in Transit, Not Able to Check Out
      return;

    // Check Off Customer
    const auto &[startStation, startTime] = inTransit[id];
    ++travelTime[startStation][endStation].first;
    travelTime[startStation][endStation].second += (t - startTime);
    inTransit.erase(id);
  }

  double getAverageTime(string startStation, string endStation) {
    return static_cast<double>(travelTime[startStation][endStation].second) /
           travelTime[startStation][endStation].first;
  }
};
