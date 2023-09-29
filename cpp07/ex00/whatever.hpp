//
// Created by Mohammad abir Abbas on 9/25/23.
//

// templates arguments should be dereferenced
// template specialization -> after original template declaration
// can be overloaded
// template - generate new class type -> stdlib ->
// parameterized type -> recipe for family of class -> container class ->
// using address not copy -> saves spaces
// compiler can write template for class+structures
// generates a new set of machine code.
// handles multiple data types with single fnc / class 
#ifndef WHATEVER_H
#define WHATEVER_H

#include <iostream>

template<typename T>

void swap(T& dog, T& cat)
{
  T tmp = dog;
  dog = cat;
  cat = tmp;
}

template<typename T>
T min(T& dog, T& cat)
{
  return (dog < cat ? dog : cat);
}

template<typename T>
T max(T& dog, T& cat)
{
  return (dog > cat ? dog : cat);
}




#endif // OBJECTSNCPP_WHATEVER_H
