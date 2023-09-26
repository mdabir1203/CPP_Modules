#pragma once

#include <iostream>

// using i++ in while starts from index 1


template< typename T>
void iter(T *arr, size_t size, void(*fnc)(T &))
{
  size_t i = 0;

  while (i < size)
  {
    fnc(arr[i]);
    i++;
  }

}

template<typename T>
void display(T &disp)
{
  std::cout << disp << std::endl;
}

