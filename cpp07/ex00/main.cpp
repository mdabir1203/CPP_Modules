//
// Created by Mohammad abir Abbas on 9/25/23.
//



/*
 #include "whatever.hpp"
 int main(void)
{
  int dog = 2;
  int cat = 3;

  ::swap(dog, cat);
  std::cout << "dog = " << dog << ", cat =" << cat << std::endl;
  std::cout << "min(dog, cat) = " << ::min(dog,cat) << std::endl;
  std::cout << "max(dog, cat) = " << ::max(dog, cat) << std::endl;


  std::string rabbit = "rabbithole1";
  std::string bat = "rabbithole2";

  ::swap(rabbit, bat);
  std::cout << "rabbit = " << rabbit << ", bat = " << bat << std::endl;
  std::cout << "min(dog, cat) = " << ::min(dog, cat) << std::endl;
  std::cout << "max(cat, dog) = " << ::max(cat, dog) << std::endl;
  std::cout << "min(rabbit, bat) = " << ::min(rabbit, bat) << std::endl;
  std::cout << "max(rabbit, bat) = " << ::max(rabbit, bat) << std::endl;



  return (0);

}*/

#include "whatever.hpp"

class Awesome
{
public:
  Awesome(void) : _n(0) {}
  Awesome( int n ) : _n( n ) {}
  Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
  bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
  bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
  bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
  bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
  bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
  bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
  int get_n() const { return _n; }
private:
  int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

int main(void)
{
  Awesome a(2), b(4);

  swap(a, b);
  std::cout << a << " " << b << std::endl;
  std::cout << max(a, b) << std::endl;
  std::cout << min(a, b) << std::endl;
  return (0);
}