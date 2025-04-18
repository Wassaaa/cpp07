#pragma once
#include <cstddef>
#include <stdexcept>

template <typename T>
class Array
{
public:
    Array()
        : _size(0)
        , _elements(nullptr) {};

    Array(unsigned int n)
        : _size(n)
        , _elements(nullptr)
    {
        if (n > 0)
            _elements = new T[n]();
    };

    Array &operator=(const Array &other)
    {
        if (this == &other)
            return *this;
        _size = other._size;
        if (_elements)
            delete[] _elements;
        if (_size > 0) {
            _elements = new T[_size]();
            for (size_t i = 0; i < _size; i++) {
                _elements[i] = other._elements[i];
            }
        }
        else {
            _elements = nullptr;
        }
        return *this;
    };

    Array(const Array &other)
        : _size(other._size)
        , _elements(nullptr)
    {
        *this = other;
    };

    ~Array()
    {
        if (_elements)
            delete[] _elements;
    }

    T &operator[](size_t index)
    {
        if (index >= _size)
            throw std::out_of_range("out of bounds");
        return _elements[index];
    };

    const T &operator[](size_t index) const
    {
        if (index >= _size)
            throw std::out_of_range("out of bounds");
        return _elements[index];
    };

    size_t size() const
    {
        return (_size);
    };

private:
    size_t _size;
    T *_elements;
};
