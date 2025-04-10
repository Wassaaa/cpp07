#pragma once

#include <iostream>

template <typename T> void print(T &element)
{
    std::cout << element << " ";
}

template <typename T> void iter(T *array, int len, void (*function)(T &))
{
    if (!array || len <= 0)
        return;
    for (int i = 0; i < len; i++) {
        function(array[i]);
    }
}
