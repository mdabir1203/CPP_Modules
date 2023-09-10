#include <iostream>

// write a static class ScalarConverter containing method "convert" taking string of c++ literals as parameters
// and returning a char, int, float or double depending on the string passed as parameter. Only decimal notations are used . Also include pseudo literals
// help me write it along with test cases
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <exception>
#include <climits>
#include <cmath>


#define NAN_INF 1
#define ERROR 2
#define CHAR 3
#define INT 4
#define FLOAT 5
#define DOUBLE 6



class ScalarConverter
{
  public:
    const std::string input;
    int               whichType;
    char              whatChar;
    int               whatInt;
    float             whatFloat;
    double            whatDouble;

    Conversion();

    int checkInput(void);
    void convertInput(void);
    void fromChar(void);
    void fromInt(void);
    void fromFloat(void);
    void fromDouble(void);

    void printOutput(void) const;
    // getters and setters
    std::string getInput(void) const;
    int getWhichType(void) const;
    char getWhatChar(void) const;
    int getWhatInt(void) const;
    float getWhatFloat(void) const;
    double getWhatDouble(void) const;


    void setInput(std::string input);
    void setWhichType(int whichType);
    void setWhatChar(char whatChar);
    void setWhatInt(int whatInt);
    void setWhatFloat(float whatFloat);

public:
    Conversion(std::string input);
    Convert(const Convert &src);

    ~Conversion();
    Convert &operator=(const Convert &src);

    class ExceptionError : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };

};

#endif