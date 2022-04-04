#pragma GCC opptimize("fast")
#include <bits/stdc++.h>
using namespace std;

class ZeroEvenOdd {
 private:
  mutex m_MutexLock;
  condition_variable m_CV;
  bool m_PrintZero;
  int m_PrintVal;
  const int m_StopVal;

 public:
  ZeroEvenOdd(int n) noexcept
      : m_PrintZero(true), m_PrintVal(1), m_StopVal(n) {}

  void zero(const function<void(int)>& printNumber) noexcept {
    while (m_PrintVal < m_StopVal || m_PrintVal == 1) {
      unique_lock uLock(m_MutexLock);
      m_CV.wait(uLock, [this] { return m_PrintZero; });
      if (m_PrintVal <= m_StopVal || m_PrintVal == 1 && m_PrintZero) {
        printNumber(0);
        m_PrintZero = false;
        uLock.unlock();
        m_CV.notify_all();
      }
    }
  }

  void even(const function<void(int)>& printNumber) noexcept {
    while (m_PrintVal < m_StopVal) {
      unique_lock uLock(m_MutexLock);
      m_CV.wait(uLock, [this] { return !m_PrintZero && m_PrintVal % 2 == 0; });
      if (m_PrintVal <= m_StopVal) {
        printNumber(m_PrintVal++);
        m_PrintZero = true;
        uLock.unlock();
        m_CV.notify_all();
      }
    }
  }

  void odd(const function<void(int)>& printNumber) noexcept {
    while (m_PrintVal < m_StopVal || m_PrintVal == 1) {
      unique_lock uLock(m_MutexLock);
      m_CV.wait(uLock, [this] { return !m_PrintZero && m_PrintVal % 2 == 1; });
      if (m_PrintVal <= m_StopVal || m_PrintVal == 1 && !m_PrintZero) {
        printNumber(m_PrintVal++);
        m_PrintZero = true;
        uLock.unlock();
        m_CV.notify_all();
      }
    }
  }
};
