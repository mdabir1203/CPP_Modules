
#pragma once

#include <iostream>

template <typename T>
class AArray
{
  private:
    T* arr_;
    unsigned int size_;

  public:
    AArray() : arr_(nullptr), size_(0);

    AArray(unsigned int n) : arr_(new T[n]()), size_(n);

    AAray(const AArray& copy);

    AAray& operator=(const AArray& copy);

    ~AArray();

    T& operator[](unsigned int idx);

    const T& operator[](unsigned int idx) const;

    unsigned int size() const {return size_;}
};

#include "Array.tpp