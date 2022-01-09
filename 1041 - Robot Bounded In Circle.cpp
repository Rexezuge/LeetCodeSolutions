#include <bits/stdc++.h>
using namespace std;

class Solution {
  enum Angle { Up, Left, Down, Right };
  class Position {
    int16_t X = 0, Y = 0;

   public:
    void move(const Angle &A) {
      switch (A) {
        case Angle::Up:
          ++Y;
          break;
        case Angle::Left:
          --X;
          break;
        case Angle::Down:
          --Y;
          break;
        case Angle::Right:
          ++X;
          break;
      }
    }
    uint16_t getAbsPosition() { return abs(0 - X) + abs(0 - Y); }
  };
  void turnLeft(Angle &A) {
    if (A == Angle::Up)
      A = Angle::Left;
    else if (A == Angle::Left)
      A = Angle::Down;
    else if (A == Angle::Down)
      A = Angle::Right;
    else if (A == Angle::Right)
      A = Angle::Up;
  }
  void turnRight(Angle &A) {
    if (A == Angle::Up)
      A = Angle::Right;
    else if (A == Angle::Left)
      A = Angle::Up;
    else if (A == Angle::Down)
      A = Angle::Left;
    else if (A == Angle::Right)
      A = Angle::Down;
  }

 public:
  bool isRobotBounded(string &instructions) {
    // Initialization
    Angle A = Angle::Up;
    Position P;
    // Calculate
    for (const auto &i : instructions)
      if (i == 'L')
        turnLeft(A);
      else if (i == 'R')
        turnRight(A);
      else if (i == 'G')
        P.move(A);
    // Yay!
    if (P.getAbsPosition() == 0) return true;
    if (A != Angle::Up) return true;
    return false;
  }
};
