#include "calculator.h"
#include <iostream>
#include <limits>

using namespace std;

int main() {
  ScientificCalculator calc;
  int choice;

  while (true) {

    cout << "\n===== Scientific Calculator =====\n";
    cout << "1. Add\n";
    cout << "2. Subtract\n";
    cout << "3. Divide\n";
    cout << "4. Multiply\n";
    cout << "5. Factorial\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";

    cin >> choice;

    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "Invalid input. Please enter a number.\n";
      continue;
    }

    if (choice == 6) {
      cout << "Exiting calculator.\n";
      break;
    }

    try {

      if (choice == 1) {
        double a, b;
        cout << "Enter two numbers: ";
        cin >> a >> b;

        cout << "Result: " << calc.add(a, b) << endl;
      }

      else if (choice == 2) {
        double a, b;
        cout << "Enter two numbers: ";
        cin >> a >> b;

        cout << "Result: " << calc.subtract(a, b) << endl;
      }

      else if (choice == 3) {
        double a, b;
        cout << "Enter two numbers: ";
        cin >> a >> b;

        cout << "Result: " << calc.divide(a, b) << endl;
      }

      else if (choice == 4) {
        double a, b;
        cout << "Enter two numbers: ";
        cin >> a >> b;

        double result = calc.multiply(a, b);

        if (result > numeric_limits<double>::max()) {
          throw overflow_error("Multiplication overflow.");
        }

        cout << "Result: " << result << endl;
      }

      else if (choice == 5) {
        int n;
        cout << "Enter a number: ";
        cin >> n;

        if (n > 20) {
          throw overflow_error(
              "Factorial too large (overflow risk). Max allowed = 20.");
        }

        cout << "Result: " << calc.factorial(n) << endl;
      }

      else {
        cout << "Invalid choice. Try again.\n";
      }

    } catch (const exception &e) {
      cout << "Error: " << e.what() << endl;
    }
  }

  return 0;
}