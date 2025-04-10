#include "Array.hpp"
#include <iostream>
int main(void)
{
    const Array<int> myArray(55);
    std::cout << myArray[5] << std::endl;
}
