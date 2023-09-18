// write a static class ScalarConverter containing method "convert" taking string of c++ literals as parameters
// and returning a char, int, float or double depending on the string passed as parameter. Only decimal notations are used . Also include pseudo literals
// help me write it along with test cases
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <exception>
#include <climits>
#include <sstream>

enum e_types {
  UNDETERMINED,
  INVALID,
  CHAR,
  INT,
  FLOAT,
  DOUBLE,
  NAN_,
  INF
};

// fnc pointer is used for -> multiple implementation of same fnc
// and choose which to use at runtime based on condition
// used in dynmamic selection -> might add runtime overhead

class ScalarConverter
{
  public:

    ScalarConverter();
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter &operator=(const ScalarConverter& copy);
    ~ScalarConverter();

    std::string getInput(void) const;
    void setInput(const std::string &str);
    e_types getType(void) const;

    void display(void);

  private:
    std::string inputs_;
    e_types type_;
    void detectType(void);
    void detectLiterals(std::string str);
    void displayChar(void) const;
    void displayInt(void) const;
    void displayDouble(void) const;
    void displayFloat(void) const;
    void displayNan(void) const;
    void displayInf(void) const;

};

#endif