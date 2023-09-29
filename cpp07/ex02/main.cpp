#include <iostream>
#include "Array.hpp"

#include <iostream>
#include "Array.hpp"



// if (size != 0) -> print error
// arr with size 10 -> check size correct
// assign val in arr with loop (with idx i)
// loop to print val each elem in array
// create copy of arr and print val
// assign val to first 3 elem of arr and check if elem correct
// assign to  5th elem of array -> (checking out of bounds) -> trigger exception
// print msg -> test passed

int main()
{

  // Testing empty array
  Array<int> emp_arr;
  if (emp_arr.size() != 0)
  {
    std::cout << "Empty array size not correct" << std::endl;
    return (1);
  }
    // Testing array with specific size (n = 10)
  Array<int> array(10);
  if (array.size() != 10){
    std::cout << "Array size not correct" << std::endl;
  }
  for (unsigned int i = 0; i < array.size(); i++) {
    array[i] = i;
  }
  for (unsigned int i = 0; i < array.size(); i++) {
    std::cout << array[i] << " ";
  }
  std::cout << std::endl;
  //Testing copied array
  Array<int> copy(array);
  for (unsigned int i = 0; i < copy.size(); i++) {
    std::cout << copy[i] << " ";
  }
  std::cout << std::endl;
  // Testing out of bound and element access

  array[0] = 3;
  array[1] = 4;
  array[2] = 5;
  if (array[0] != 3 || array[1] != 4 || array[2] != 5)
  {
    std::cout << "Element access not correct" << std::endl;
    return (1);
  }
  try {
    array[5] = 13;
  } catch (std::out_of_range& e){
    std::cout << "yo bro you are out" << std::endl;
  } catch (...) {
    std::cout << "Unexpected exception caught" << std::endl;
    return (1);
  }
  std::cout << "All tests passed" << std::endl;
  return 0;
}