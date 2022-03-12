#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class FooBar {
 private:
  int n;
  atomic<bool> fb = false;

 public:
  FooBar(int n) { this->n = n; }

  void foo(function<void()> printFoo) {
    for (int i = 0; i < n; i++) {
      while (fb == true) this_thread::yield();
      printFoo();
      fb = true;
    }
  }

  void bar(function<void()> printBar) {
    for (int i = 0; i < n; i++) {
      while (fb == false) this_thread::yield();
      printBar();
      fb = false;
    }
  }
};
