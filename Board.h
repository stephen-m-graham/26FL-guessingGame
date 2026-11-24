/**
* @file   Board.h
* @author Stephen Graham
* @date   2026-11-24
* @brief  A 2d-array implementation of a board
*/
#pragma once

/**
* @class Board
* @brief A 2-D board of fixed size (4x4) of characters
* 
* @details This board is a small representation of a board like Battleship
* that can have things put into it.
* 
* @code{.cpp}
* Board myBoard('~');
* myBoard.erase();
* myBoard.at(1,1) = 'X';
* if (myBoard.at(1,1) == 'X') ++counter;
* @endcode
*/
class Board {
private:
  const int ROWS = 4;
  const int COLS = 4;
  char board[4][4]{};
  char fill;
public:
  Board(char fillCharacter = '.');

  // Accessors
  /**
   * @brief Provide an accessor for the board if it is non-const
   * @param[in] row the 0-based row number
   * @param[in] col the 0-based column number
   * @return char by reference into the board
   * 
   * The char& gives a reference into the array (think of pass-by-reference)
   * It allows me to also assign into that reference.
   * 
   * For more information on the overloading
   * Member functions and cv-qualifiers (const overloads):
   *    https://en.cppreference.com/w/cpp/language/member_functions
   * General function overloading rules:
   *    https://en.cppreference.com/w/cpp/language/overload_resolution
   */
  char& at(int row, int col);

  /**
   * @brief Provide an accessor for the board if it is const
   * @param[in] row the 0-based row number
   * @param[in] col the 0-based column number
   * @return char by reference into the board
   * 
   * The char& is still a reference, but it is unassignable and used when the 
   * value will not or cannot be changed.
   */
  const char& at(int row, int col) const;

  /**
   * @brief set every element in the array to the fill character
   */
  void erase();

  /**
   * @brief Display the board and any characters on it
   * @param hidden determines whether or not to show the actual contents
   * 
   * @todo  this will require refactoring if we change the board size
   */
  void display(const bool hidden=false);
};
