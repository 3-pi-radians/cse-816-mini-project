#include <cassert>
#include <iostream>

// include calculator functions
#include "../src/calculator.cpp"

int main() {

  assert(add(2, 3) == 5);
  assert(subtract(10, 4) == 6);
  assert(multiply(3, 5) == 15);
  assert(divide(10, 2) == 5);

  std::cout << "All arithmetic tests passed successfully!" << std::endl;

  return 0;
}