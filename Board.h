/**
* @file   Board.h
* @author Stephen Graham
* @date   2026-11-24
* @brief  A 2d-array implementation of a board
*/
#pragma once
class Board {
private:
  const int ROWS = 4;
  const int COLS = 4;
  char board[4][4]{};
  char fill;
  char picked = '#';
public:
  Board(char fillCharacter = '.');

  // Accessors
  char& at(int row, int col);

  /**
   * @brief Provide a read/write accessor for the board
   * @param row the 0-based row number
   * @param col the 0-based column number
   * @return char by reference into the board
   */
  const char& at(int row, int col) const;
  void erase();

  // display

  /**
   * @brief Display the board and any characters on it
   * @param hidden 
   * @return 
   */
  bool display(const bool hidden=false);
};
