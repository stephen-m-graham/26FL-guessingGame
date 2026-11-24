/**
* @file     main.cpp
* @author   Stephen Graham
* @date     2026-11-24
* @brief    demonstrate a 2D board that can be hidden
* 
* The board in Board is a fixed, 4x4 board.
* 
*/
#include <iostream>
#include "Board.h"
#include "Random.h"

int main() {
  Board myBoard; // the board with a hidden X
  Board myPicks; // a board with places I have picked
  RNG random(4);

  std::cout << "Placing an 'X' at position 2,3" << std::endl;
  myBoard.at(2, 3) = 'X';

  std::cout << "Display the board - visible" << std::endl;
  myBoard.display(false); // not hidden (default behaviour)

  std::cout << "Display the board - hidden" << std::endl;
  myBoard.display(true);  // hidden

  std::cout << "Clearing the board" << std::endl;
  myBoard.erase();

  std::cout << "Hiding an X somewhere" << std::endl;
  {
    int hideRow = random.roll() - 1; // -1 because dice are 1-4
    int hideCol = random.roll() - 1; // -1 because dice are 1-4
    myBoard.at(hideRow, hideCol) = 'X';
  }

  std::cout << "Try to find the X" << std::endl;
  bool found = false;
  while (!found) {
    int row = 0, col = 0;
    std::cout << "Enter a row and column (e.g. 0 0): ";
    std::cin >> row >> col; // TODO - sanitize the input
    found = (myBoard.at(row, col) == 'X');
    if (!found) {
      myPicks.at(row, col) = ' ';
    }
    else {
      myPicks.at(row, col) = '*';
    }
    myPicks.display();
  }

  return 0;
}