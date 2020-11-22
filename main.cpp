#include <iostream>

class Sudoku {
private:
  static const int limit = 9;
  int x = -1;
  int y = 0;
  int table[limit][limit] = {};
  bool mask[limit][limit] = {};

  bool next() {
    bool result = true;
    if(++x == limit) {
      x = 0;
      if(++y == limit) {
        return false;
      }
    }
    if (mask[y][x]) {
      result = next();
    }
    return result;
  }

  bool prev() {
    bool result = true;
    if(--x < 0) {
      x = limit - 1;
      if(--y < 0) {
        return false;
      }
    }
    if (mask[y][x]) {
      result = prev();
    }
    return result;
  }

  bool check() {
    // check row
    for (int i = 0; i < limit; i++)
      if (table[y][i] == table[y][x] && i != x)
        return false;

    // check column
    for (int i = 0; i < limit; i++)
      if (table[i][x] == table[y][x] && i != y)
        return false;

    // check square
    int start_x, start_y;
    if (x < 3)
      start_x = 0;
    else if (x < 6)
      start_x = 3;
    else
      start_x = 6;
    
    if (y < 3)
      start_y = 0;
    else if (y < 6)
      start_y = 3;
    else
      start_y = 6;

    for (int i = start_y; i < start_y + 3; i++)
      for (int j = start_x; j < start_x + 3; j++)
        if (table[i][j] == table[y][x] && i != y && j != x)
          return false;

    return true;
  }

public:
  Sudoku() {}

  void solve() {
    while (next()) {
      do {
        while (++table[y][x] > 9) {
          table[y][x] = 0;
          if (!prev()) {
            std::cout << "Unsolvable!" << std::endl;
            return;
          }
        }
      } while (!check());
    }
  }

  void enterDigits() {
    std::cout << "Enter Sudoku table digits line by line with 0s as vacant positions" << std::endl;
    for (int i = 0; i < limit; i++)
      for (int j = 0; j < limit; j++) {
        std::cin >> table[i][j];
        if(table[i][j] != 0)
          mask[i][j] = 1;
      }
  }

  void print() {
    std::cout << std::endl;
    for (int i = 0; i < limit; i++) {
      for (int j = 0; j < limit; j++)
        std::cout << table[i][j] << "  ";
      std::cout << std::endl;
    }
  }

};

int main() {
  Sudoku s;
  s.enterDigits();
  s.solve();
  s.print();
  return 0;
}
