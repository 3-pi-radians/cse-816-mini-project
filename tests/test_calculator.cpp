#include <cassert>
#include <iostream>

// include calculator functions
#include "../src/calculator.h"

int main() {
  ScientificCalculator calc;
  assert(calc.add(2, 3) == 5);
  assert(calc.subtract(10, 4) == 6);
  assert(calc.multiply(3, 5) == 15);
  assert(calc.divide(10, 2) == 5);

  std::cout << "All arithmetic tests passed successfully!" << std::endl;

  return 0;
}