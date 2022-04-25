#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class Iterator {
  struct Data;
  Data* data;

 public:
  Iterator(const vector<int>& nums);
  Iterator(const Iterator& iter);

  // Returns the next element in the iteration.
  int next();

  // Returns true if the iteration has more elements.
  bool hasNext() const;
};

class PeekingIterator : public Iterator {
  int nextValue = 0;

 public:
  PeekingIterator(const vector<int>& nums) noexcept
      : Iterator(nums), nextValue(Iterator::next()) {}

  // Returns the next element in the iteration without advancing the iterator.
  int peek() noexcept { return nextValue; }

  // hasNext() and next() should behave the same as in the Iterator interface.
  // Override them if needed.
  int next() noexcept {
    int tmpValue = nextValue;
    (Iterator::hasNext()) ? (nextValue = Iterator::next()) : (nextValue = 0);
    return tmpValue;
  }

  bool hasNext() const noexcept { return nextValue != 0; }
};

#if 0
class PeekingIterator : public Iterator {
 public:
  PeekingIterator(const vector<int>& nums) noexcept : Iterator(nums) {}

  // Returns the next element in the iteration without advancing the iterator.
  int peek() noexcept {
    Iterator i = *this;
    return i.next();
  }
};
#endif
