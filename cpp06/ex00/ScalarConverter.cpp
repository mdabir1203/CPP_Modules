#include "ScalarConverter.hpp"

Conversion::Conversion(void)
{
    std::cout << "Default constructor called" << std::endl;
}

Conversion::Conversion(const std::string input) :: input(input)
{
    std::cout << "Conversion constructor for " << this->getInput() << std::endl;
    this->double = atof(this->input.c_str());
    this->convertInput();
    this->printOutput();
}

Conversion::Conversion(const Conversion &src) : input(src.getInput())
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    this->printOutput();
}

Conversion::~Conversion()
{
    std::cout << "Destructor called" << std::endl;
}

Conversion &Conversion::operator=(const Conversion &src)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &src)
    {
      return *this;
    }
    this->input = src.getInput();
    this->whichType = src.getWhichType();
    this->whatChar = src.getWhatChar();
    this->whatInt = src.getWhatInt();
    this->whatFloat = src.getWhatFloat();
    this->whatDouble = src.getWhatDouble();
    return *this;
}

int Conversion::checkInput()
{
    if (this->getInput().compare("nan") == 0 || this->getInput().compare("+inf") == 0 || this->getInput().compare("-inf") == 0 \
        || this->getInput().compare("+inff") == 0 || this->getInput().compare("-inff") == 0)
    {
      return (NAN_INF);
    }
    else if (this->getInput().length() == 1 && (this->getInput()[0] == '+' || this->getInput()[0] == '-') \
            this->getInput()[0] == 'f' || this->getInput()[0] == '.')
    {
      return (CHAR);
    }
    else if (this->getInput().find_first_of("+-") != this->getInput().find_last_of("+-"))
        return (ERROR);
    else if (this->getInput().find_first_not_of("+-0123456789") == std::string::npos)
        return (INT);
    else if (this->getInput().find_first_not_of("+-0123456789.") == std::string::npos)
    {
        // (catching 0..0 / 0. / .0)
        if (this->getInput().find_first_of(".") != this->getInput().find_last_of(".") \
          || isdigit(this->getInput()[this->getInput().find_first_of(".") + 1] == false
                       || this->getInput().find_first_of(".") == 0)
            )
            return (ERROR);
        else
            return (DOUBLE);
    }
    else if (this->getInput().find_first_not_of("+-0123456789.f") == std::string::npos)
    {
        // catching 0.0ff or 0..0f or 0.f the edge cases of error
        if (this->getInput().find_first_of("f") != this->getInput().find_last_of("f") \
          || this->getInput().find_first_of(".") != this->getInput().find_last_of(".") \
          || this->getInput().find_first_of(".") == 0 ||
          this->getInput()[this->getInput().find_first_of("f") + 1] != '\0')
            return (ERROR);
        else
            return (FLOAT);
    }
    else if ((this->getInput().length() == 1 && std::isprint(this->getInput()[0])) ||
             (this->getInput().length() == 1 && std:.isalpha(this->getInput()[0])))
    {
        return (CHAR);
    }
    else
        return (ERROR);
}

void Conversion::fromChar(void)
{
    this->char = static_cast<unsigned char>(this->getInput()[0]);
    this->whatInt = static_cast<int>(this->getChar());
    this->whatFloat = static_cast<float>(this->getChar());
    this->whatDouble = static_cast<double>(this->getChar());
}

void Conversion::fromInt(void)
{
    this->whatInt = static_cast<int>(this->getDouble());
    this->whatChar = static_cast<unsigned char>(this->getInt());
    this->whatFloat = static_cast<float>(this->getDouble());
}

void Conversion::fromFloat(void)
{
    this->whatFloat = static_cast<float>(this->getDouble());
    this->whatChar = static_cast<char>(this->getFloat());
    this->whatInt = static_cast<int>(this->getFloat());
}

void Conversion::fromDouble(void)
{
    this->whatChar = static_cast<char>(this->getDouble());
    this->whatInt = static_cast<int>(this->getDouble());
    this->whatFloat = static_cast<float>(this->getDouble());
}

void Conversion::convertInput(void)
{
    // create me a function pointer array to convert from char, int ,float and double . Also add an exception
    void (Conversion::*convertTypes[4])(void) = {&Conversion::fromChar, &Conversion::fromInt, &Conversion::fromFloat, &Conversion::fromDouble};
    int types[] = {CHAR, INT, FLOAT, DOUBLE};

    this->type = checkInput();

    if(this->getType() == NAN_INF)
        return ;
    int i = 0;
    while (i++ < 4)
    {
        if (this->getType() == types[i])
        {
            (this->*convertTypes[i])();
            break;
        }
        if (i == 4)
            throw Conversion::ExceptionError();
    }
}

void Conversion::printOutput(void) const
{
    if (this->getType() != NAN_INF && this->getDouble() <= UCHAR_MAX && this->getDouble() >= 0)
    {
        if (isprint(this->getChar()))
            std::cout << "char: " << this->getChar() << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: Naaa" << std::endl;

    if (this->getType() != NAN_INF && this->getDouble() >= std::numeric_limits<int>::min() \
        && this->getDouble() <= std::numeric_limits<int>::max())
    {
        std::cout << "int: " << this->getInt() << std::endl;
    }
    else
        std::cout << "int: not valid to display" << std::endl;
}
