#include "iter.hpp"

/*#define N 5

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
}*/


#include <iostream>
#include "iter.hpp"
using namespace std;

class Awesome {
public:
  Awesome( void ) : _n( 42 ) { return; }
  int get (void) const { return this->_n; }
private:
  int _n;
};
std::ostream &operator << (std::ostream & a, Awesome const &rhs) { a << rhs.get(); return (a); }
template <typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int main() {
  int tab[] = {0, 1, 2, 3, 4}; //< I never understood why you can't write int[] tab. Wouldn't that make more sense?
  Awesome tab2[5];
  iter(tab, 5, display);
  iter(tab2, 2, display);

  // I don't see the declaration of the iter function here. Please include it before the main function, or provide me with the declaration of the iter function.

  return (0);
}
