#include <iostream>
#include "sudoku.hpp"


int main() {
  Sudoku s;
  s.enterDigits();
  s.solve();
  s.print();
  return 0;
}
