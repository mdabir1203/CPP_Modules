#include "iter.hpp"

#define N 5

int main(void)
{
  int arrA[] = {5,4,3,2,1};

  std::cout << "array A: " << std::endl;
  iter(arrA, N, &display);

  double arrB[] = {5.5,4.5,3.5,2.5,1.5};

  std::cout << "\narray B: " << std::endl;
  iter(arrB, N, display);

  char arrC[] = {'y','x','q','c','e', 'f'};

  std::cout << "\narray C: " << std::endl;
  iter(arrC, N, &display);

  std::string arrD[] = {"who", "are", "you", "speaking", "to", "?"};

  std::cout << "\narray D: " << std::endl;
  iter(arrD, N, &display);

  return (0);
}


