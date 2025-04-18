#include "Array.hpp"
#include <iostream>
#include <string>

#define MAX_VAL 750

// Simple struct to test with custom types
struct Point {
  int x;
  int y;

  Point() : x(0), y(0) {}
  Point(int _x, int _y) : x(_x), y(_y) {}

  bool operator==(const Point &other) const {
    return (x == other.x && y == other.y);
  }
};

void printTestResult(bool success, const std::string &testName) {
  std::cout << (success ? "✅ " : "❌ ") << testName
            << (success ? " passed!" : " failed!") << std::endl;
}

int main(int, char **) {
  std::cout << "\n=== ARRAY TEMPLATE CLASS TESTS ===\n" << std::endl;

  // TEST 1: Default constructor (empty array)
  {
    std::cout << "Testing default constructor..." << std::endl;
    Array<int> empty;
    bool success = (empty.size() == 0);
    printTestResult(success, "Default constructor");
  }

  // TEST 2: Parameterized constructor
  {
    std::cout << "\nTesting parameterized constructor..." << std::endl;
    Array<int> numbers(5);
    bool success = (numbers.size() == 5);

    // Check if initialized with default values
    bool defaultValues = true;
    for (size_t i = 0; i < numbers.size(); i++) {
      if (numbers[i] != 0) {
        defaultValues = false;
        break;
      }
    }

    printTestResult(success, "Size check");
    printTestResult(defaultValues, "Default initialization");
  }

  // TEST 3: Copy constructor and assignment operator
  {
    std::cout << "\nTesting copy constructor and assignment operator..."
              << std::endl;

    Array<int> original(3);
    original[0] = 10;
    original[1] = 20;
    original[2] = 30;

    // Test copy constructor
    Array<int> copied(original);
    bool copySuccess = (copied.size() == original.size());
    for (size_t i = 0; i < original.size() && copySuccess; i++) {
      copySuccess = (copied[i] == original[i]);
    }

    // Modify original to test deep copy
    original[0] = 100;
    bool deepCopySuccess = (copied[0] == 10); // Should still be 10

    // Test assignment operator
    Array<int> assigned;
    assigned = original;
    bool assignSuccess = (assigned.size() == original.size());
    for (size_t i = 0; i < original.size() && assignSuccess; i++) {
      assignSuccess = (assigned[i] == original[i]);
    }

    // Modify original again
    original[1] = 200;
    bool deepAssignSuccess = (assigned[1] == 20); // Should still be 20

    printTestResult(copySuccess, "Copy constructor - content");
    printTestResult(deepCopySuccess, "Copy constructor - deep copy");
    printTestResult(assignSuccess, "Assignment operator - content");
    printTestResult(deepAssignSuccess, "Assignment operator - deep copy");
  }

  // TEST 4: Out-of-bounds access
  {
    std::cout << "\nTesting boundary checks..." << std::endl;
    Array<int> arr(3);

    bool negativeIndexThrows = false;
    try {
      arr[-1] = 0;
    } catch (const std::exception &) {
      negativeIndexThrows = true;
    }

    bool outOfBoundsThrows = false;
    try {
      arr[3] = 0;
    } catch (const std::exception &) {
      outOfBoundsThrows = true;
    }

    printTestResult(negativeIndexThrows, "Negative index check");
    printTestResult(outOfBoundsThrows, "Upper bound check");
  }

  // TEST 5: Different types
  {
    std::cout << "\nTesting with different types..." << std::endl;

    // String array
    Array<std::string> strArray(2);
    strArray[0] = "Hello";
    strArray[1] = "World";
    bool strSuccess = (strArray[0] == "Hello" && strArray[1] == "World");

    // Custom type array
    Array<Point> points(2);
    points[0] = Point(1, 2);
    points[1] = Point(3, 4);
    bool pointSuccess = (points[0] == Point(1, 2) && points[1] == Point(3, 4));

    printTestResult(strSuccess, "String array");
    printTestResult(pointSuccess, "Custom type array");
  }

  // TEST 5: Big Random
  {
    std::cout << "\nRunning original random value test..." << std::endl;

    Array<int> numbers(MAX_VAL);
    int *mirror = new int[MAX_VAL];
    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++) {
      const int value = rand();
      numbers[i] = value;
      mirror[i] = value;
    }

    // Creating temporary copies to test scope
    {
      Array<int> tmp = numbers;
      Array<int> test(tmp);
    }

    // Verify values weren't changed
    bool valuesMatch = true;
    for (int i = 0; i < MAX_VAL; i++) {
      if (mirror[i] != numbers[i]) {
        valuesMatch = false;
        break;
      }
    }

    printTestResult(valuesMatch, "Random values test");

    delete[] mirror;
  }

  std::cout << "\nAll tests completed!\n" << std::endl;
  return 0;
}