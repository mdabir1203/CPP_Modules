#include "ScalarConverter.hpp"

int main(int argc,char **argv)
{
  if (argc != 2) {
    std::cout << "Usage: [./convert <char, int, float or double>]" << std::endl;
    return 0;
}
std::string str = argv[1];

ScalarConverter converter = ScalarConverter();
converter.setInput(str);
converter.display();
}
