#include "Board.h"
#include <iostream>
#include <format>

Board::Board(char fillCharacter) {
  fill = fillCharacter;
  erase();
}

char& Board::at(int row, int col) {
  return board[row][col];
}

const char& Board::at(int row, int col) const {
  return board[row][col];
}

void Board::erase() {
  for (auto r = 0; r < ROWS; ++r) {
    for (auto c = 0; c < COLS; ++c) {
      at(r, c) = fill;
    }
  }
}

void Board::display(const bool hidden)
{
  using std::cout;
  using std::endl;
  using std::format;

  cout << format("    0  1  2  3 ") << endl;    // column indicators
  for (auto r = 0; r < ROWS; ++r) {
    cout << format("{0:^3}", r);                // row indicators
    for (auto c = 0; c < COLS; ++c) {
      // print the fill character if hidden or the character in the array if not
      cout << format("{0:^3}", (hidden)?fill:at(r,c) );
    }
    cout << endl;
  }
}