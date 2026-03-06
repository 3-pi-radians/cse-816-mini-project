#include "calculator.h"
#include <cmath>

double ScientificCalculator::add(double a, double b) { return a + b; }

double ScientificCalculator::subtract(double a, double b) { return a - b; }

double ScientificCalculator::multiply(double a, double b) { return a * b; }

double ScientificCalculator::divide(double a, double b) {
  if (b == 0)
    throw std::invalid_argument("Cannot divide by zero.");
  return a / b;
}

unsigned long long ScientificCalculator::factorial(int n) {
  if (n < 0)
    throw std::invalid_argument("Factorial undefined for negative values.");
  unsigned long long result = 1;
  for (int i = 2; i <= n; i++)
    result *= i;
  return result;
}