/**
 * RCOS-EasyContact
 * EasyContact/Backend/include/EasyContact
 * ColorfulOutput.hpp
 * Copyright [2013] <Joel Sjögren>
 */
#ifndef BACKEND_INCLUDE_EASYCONTACT_COLORFULOUTPUT_HPP_
#define BACKEND_INCLUDE_EASYCONTACT_COLORFULOUTPUT_HPP_
// C++ Standard Library
#include <ostream>
namespace COLOR {
enum VALUE {
  FG_RED = 31,
  FG_GREEN = 32,
  FG_BLUE = 34,
  FG_DEFAULT = 39,
  BG_RED = 41,
  BG_GREEN = 42,
  BG_BLUE = 44,
  BG_DEFAULT = 49
};
class Modifier {
 private:
  VALUE __CODE;

 public:
  Modifier(const VALUE& INPUT) : __CODE(INPUT) {}
  friend std::ostream& operator<<(std::ostream& FILE,
                                  const Modifier& INSTANCE) {
    return FILE << "\033[" << INSTANCE.__CODE << "m";
  }
};
}  // namespace COLOR
#endif  // BACKEND_INCLUDE_EASYCONTACT_COLORFULOUTPUT_HPP_

#include <iomanip>
#include <iostream>
#include <vector>
#define PRACTICE_NEEDED 60

int main(void) {
  std::cout << "Enter Your Progress: ";
  size_t Q;
  std::cin >> Q;
  Q = Q / 10;
  if (Q >= PRACTICE_NEEDED) {
    Q = PRACTICE_NEEDED;
  }
  size_t DIFF = PRACTICE_NEEDED - Q;
  double PERCENT = (double)Q / PRACTICE_NEEDED * 100;
  COLOR::Modifier DEFAULT(COLOR::FG_DEFAULT);
  std::vector<COLOR::Modifier> GOOGLE_COLOR{
      COLOR::Modifier(COLOR::FG_BLUE),  COLOR::Modifier(COLOR::FG_RED),
      COLOR::Modifier(COLOR::FG_GREEN), COLOR::Modifier(COLOR::FG_BLUE),
      COLOR::Modifier(COLOR::FG_GREEN), COLOR::Modifier(COLOR::FG_RED)};
  std::vector<char> GOOGLE_NAME{'G', 'O', 'O', 'G', 'L', 'E'};
  std::cout << "[";
  size_t i = 0;
  while (Q > 0) {
    std::cout << GOOGLE_COLOR[i] << GOOGLE_NAME[i];
    if (++i >= GOOGLE_COLOR.size()) {
      i = 0;
    }
    --Q;
  }
  std::cout << DEFAULT;
  while (DIFF > 0) {
    std::cout << GOOGLE_NAME[i];
    if (++i >= GOOGLE_COLOR.size()) {
      i = 0;
    }
    --DIFF;
  }
  std::cout << "] - " << std::setprecision(3) << PERCENT << "%" << std::endl
            << std::flush;
  return EXIT_SUCCESS;
}
