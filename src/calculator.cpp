#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;

class ScientificCalculator {
public:
  double add(double a, double b) { return a + b; }
  double subtract(double a, double b) { return a - b; }
  double multiply(double a, double b) { return a * b; }
  double divide(double a, double b) {
    if (b == 0)
      throw invalid_argument("Cannot divide by zero.");
    return a / b;
  }
  double power(double a, double b) { return pow(a, b); }
  double sqrt(double a) {
    if (a < 0)
      throw invalid_argument("Cannot take square root of negative number.");
    return sqrt(a);
  }
  double sin(double x) { return sin(x * M_PI / 180.0); }
  double cos(double x) { return cos(x * M_PI / 180.0); }
  double tan(double x) { return tan(x * M_PI / 180.0); }
  double log(double x, double base = exp(1.0)) {
    if (x <= 0)
      throw invalid_argument("Logarithm undefined for non-positive values.");
    return log(x) / log(base);
  }
  unsigned long long factorial(int n) {
    if (n < 0)
      throw invalid_argument("Factorial undefined for negative values.");
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i)
      result *= i;
    return result;
  }
};

int main() {
  ScientificCalculator calc;
  int choice;
  double a, b, result;
  while (true) {
    cout << "\nScientific Calculator Menu:\n";
    cout << "1. Add\n";
    cout << "2. Subtract\n";
    cout << "3. Multiply\n";
    cout << "4. Divide\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 5)
      break;
    switch (choice) {
    case 1:
      cout << "Enter two numbers: ";
      cin >> a >> b;
      result = calc.add(a, b);
      cout << "Result: " << result << endl;
      break;
    case 2:
      cout << "Enter two numbers: ";
      cin >> a >> b;
      result = calc.subtract(a, b);
      cout << "Result: " << result << endl;
      break;
    case 3:
      cout << "Enter two numbers: ";
      cin >> a >> b;
      result = calc.multiply(a, b);
      cout << "Result: " << result << endl;
      break;
    case 4:
      cout << "Enter two numbers: ";
      cin >> a >> b;
      try {
        result = calc.divide(a, b);
        cout << "Result: " << result << endl;
      } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
      }
      break;
    default:
      cout << "Invalid choice. Try again." << endl;
    }
  }
  cout << "Exiting calculator.\n";
  return 0;
}
