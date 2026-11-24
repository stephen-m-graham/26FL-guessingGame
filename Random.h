/**
* @file   Random.h
* @author Stephen Graham
* @date   2026-11-24
* 
* @brief This implements all the random features for my program
* 
* @requires <random>
* @requires C++17 or later
*/
#pragma once
#include <random>
#include <stdexcept>>

class RNG {
private:
  int sides;
  int currentValue;
  std::uniform_int_distribution<int> dist;

  // the inline keyword lets this be defined and seeded with out a separate .cpp
  // the thread_local keyword allows for multi-threaded applications
  inline thread_local static std::mt19937 gen{ std::random_device{}() };

public:
  /**
   * @brief     explicit constructor that sets the number of sides and establishes the distribution
   * @param[in] numSides int the number of possibilities
   * @pre       the number of sides >= 2
   */
  explicit RNG(int numSides = 6) : sides(numSides), dist(1, numSides) {
    if (numSides < 2) {
      throw std::invalid_argument("A die must have at least 2 sides");
    }
    roll();
  }

  /**
   * @brief roll the randome number generator, update the current value, return the result
   * @return int the value generated
   */
  int roll() {
    currentValue = dist(gen);
    return currentValue;
  }

  // Accessors
  int getValue() const { return currentValue; }
  int getSides() const { return sides; }

  /**
   * @brief Allow a deterministic seed for testing/debugging
   * @param s unsigned int - a designated seed value
   */
  static void seed(unsigned int s) {
    gen.seed(s);
  }
};