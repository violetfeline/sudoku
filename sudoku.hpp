#pragma once


class Sudoku {
private:
  static const int limit = 9;
  int x = -1;
  int y = 0;
  int table[limit][limit] = {};
  bool mask[limit][limit] = {};

  bool next();
  bool prev();
  bool check();
public:
  Sudoku() {};
  void solve();
  void enterDigits();
  void print();


};

