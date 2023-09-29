#pragma once

#include <iostream>

template <typename T>
class Array
{
  private:
    T* data;
    unsigned int size_; // keeps track of size of array

  public:
    Array();
    Array(unsigned int n);
    Array(const Array& copy);
    ~Array();

    T& operator[](unsigned int idx) const;
    unsigned int size() const;
};

#include "Array.tpp"