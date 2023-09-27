#pragma once

#include <iostream>

template <typename T>
class Array
{
  private:
    T* arr_;
    unsigned int size_;

  public:
    Array() : arr_(NULL), size_(0){};

    Array(unsigned int n) : arr_(new T[n]()), size_(n){};

    Array(const Array& copy);

    Array& operator=(const Array& copy);

    ~Array();

    T& operator[](unsigned int idx);

    const T& operator[](unsigned int idx) const;

    unsigned int size() const;
};

#include "Array.tpp"