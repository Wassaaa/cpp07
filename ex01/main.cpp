#include "iter.hpp"

void timesTwo(int &a)
{
    a *= 2;
}

int main(void)
{
    // Test with various types
    int intArray[3] = {1, 2, 3};
    double doubleArray[3] = {1.1, 2.2, 3.3};
    std::string strArray[2] = {"Hello", "World"};

    std::cout << "Int array: ";
    iter(intArray, 3, print<int>);
    std::cout << std::endl;

    std::cout << "Double array: ";
    iter(doubleArray, 3, print<double>);
    std::cout << std::endl;

    std::cout << "String array: ";
    iter(strArray, 2, print<std::string>);
    std::cout << std::endl;

    return 0;
}
