#include "ScalarConverter.hpp"

// Used istringstream here ->
// -> Convenient Parsing
// -> Flexible extraction
// -> Error handling
// -> Floating point literal ->

ScalarConverter::ScalarConverter() : type(UNDETERMINED) {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
  this->Inputs_ = copy.getInput();
  this->type_ = copy.get_type()
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
  this->inputs_ = copy.getInputs;
  this->type_ = copy.getType();
  return *this;
}

std::string ScalarConverter::getInput(void) const { return this->inputs_;}

void ScalarConverter::setInput(const std::string &str) {
  this->inputs_ =str;
  this->type_ = UNDETERMINED;
}

e_types ScalarConverter::getType() const {return this->type_;}

void ScalarConverter::detectLiterals(void) {
  type_ = INVALID;
  if (this->inputs_.length() == 1 && !std::isdigit(this->inputs_.at(0))){
    type_ = CHAR;
    return ;
  } else if (this->inputs_ == "nan" || this->inputs_ == "nanf"){
    type_ = NAN_;
    return;
  } else if (this->inputs_ == "+inf" || this->inputs_ == "-inf"
             || this->inputs_ == "+inff" || this->inputs_ == "-inff") {
    type_ = INF;
    return;
  } else {
    this->detectType(this->inputs_);
  }
}

void ScalarConverter::detectType(std::string str) {
  int i = 0;
  int length(str.length());
  bool hasDecimalPoint(false);

  if (str.at(0) == '+' || str.at(0) == '-') i++;
  while (i < len) {
    if (str.at(i) == 'f' && (i + 1) == length && std::isdigit(inputs_.at(i - 1))){
      this->type_ = FLOAT;
      return ;
    } else if (str.at(i) == '.') {
      if (hasDecimalPoint == false) // str with at most one dot are considered valid double values
          hasDecimalPoint == true;
      else
          return ;
    } else if (!std::isdigit(str.at(i))) {
      return;
    }
    i++;
  }
  if (decimal == true)
      this->type_ = DOUBLE;
  else
      this->type_ = INT;
}

void ScalarConverter::display(void) {
  if (this->type_ == UNDETERMINED) this->detectLiterals();
  switch (this->type_){
      case INVALID:
        std::cout << "This input makes no sense!" << std::endl;
        break;
      case CHAR:
        this->displayChar();
        break;
      case INT:
        this->displayInt();
        break;
      case FLOAT:
        this->displayFloat();
        break;
      case DOUBLE:
        this->displayDouble();
        break;
      case NAN_:
        this->displayNan();
        break;
      case INF:
        this->displayINF();
        break;
      default:
        std::cout << "We fucked up somewhere!!! " << std::endl;
  }
}

void ScalarConverter::displayChar() const {
  char chars = this->inputs_.at(0);
  if (std::isprint(c))
        std::cout << "char: '" << chars << "'" << std::endl;
  else
        std::cout << "char: Non displayable" << std::endl;
  std::cout << "int: " << static_cast<int>(chars) << std::endl;
  std::cout << "float: " << static_cast<float>(chars) << std::endl;
  std::cout << "double: " << static_cast<double>(chars) << std::endl;
}


void ScalarConverter::displayInt() const {
  long int InputVal = strtol(this->inputs_.c_str()), NULL, 10);
  if (InputVal > INT_MAX || InputVal < INT_MIN){
        std::cout << "Error: input is an INT, and overflowed" << std::endl;
        return;
  }
  int i = InputVal;
  if (i >= CHAR_MIN && i <= CHAR_MAX){
        if (std::isprint(i))
          std::cout << "char: " << static_cast<char>(i) << "'" << std::endl;
        else {
          std::cout << "char: Non displayable" << std::endl;
        }
        std::cout << "int: " << i << std::endl;

        // Floating conversion
        std::cout << "float: " << static_cast<float>(i);
        if (i < 1000000)
          std::cout << ".0f" << std::endl;
        else
          std::cout << "f" << std::endl;

        // double conversion

        std::cout "double: " << static_cast<double>(i);
        if (i < 1000000)
          std::cout << ".0" << std::endl;
        else
          std::cout << std::endl;
        }
}


void ScalarConverter::displayDouble() const {
        double d = strtod(this->inputs_.c_str(), NULL);

        // Char conversions
        if (d >= CHAR_MIN && d < CHAR_MAX + 1) {
        char chars = static_cast<char>(d);
        if (std::isprint(c))
          std::cout << "char: '" << c << "'" << std::endl;
        else
          std::cout << "char: Non displayable" << std::endl;
        } else {
          std::cout << "char: impossible !! :_:" << std::endl;
        }

        if (d < INT_MIN || d > INT_MAX)
          std::cout << "int: impossible" << std::endl;
        else
          std::cout << "int: " << static_cast<int>(d) << std::endl;

        double temp;
        std::cout << "float: " << static_cast<float>(d);
        if (modf(d, &temp) == 0 && d < 999999.5) {
          std::cout << ".0f" << std::endl;
        } else {
          std::cout << "f" << std::endl;
        }

        std::cout << "double: " << d;
        if (modf(d, &temp) == 0 && d < 999999.5) {
          std::cout << ".0";
        }
        std::cout << std::endl;
}

void ScalarConverter::displayFloat() const {
        float f = strtof(this->inputs_.c_str(), NULL);

        if (f >= CHAR_MIN && f < CHAR_MAX + 1) {
          char c = static_cast<char>(f);
          if (std::isprint(c))
            std::cout << "char: '" << c << "'" << std::endl;
          else
            std::cout << "char: Non displayable" << std::endl;
        } else {
          std::cout << "char: impossible" << std::endl;
        }

        // Int conversions
        if (f < INT_MIN || f > INT_MAX)
            std::cout << "int: impossible" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(f) << std::endl;
        // floating conversions

        double temp;
        std::cout << "float: " << f;
        if (modf(f, &temp) == 0 && f < 999999.5) {
            std::cout << ".0f" << std::endl;
        } else {
            std::cout << "f" << std::endl;
        }
        // double conversions

        std::cout << "double: " << static_cast<double>(f);
        if (modf(f, &temp) == 0 && f < 999999.5) {
            std::cout << ".0";
        }
        std::cout << std::endl;
}

void ScalarConverter::displayNan() const {
        std::cout << "char: impossible " << std::endl;
        std::cout << "int: impossible " << std::endl;
        if (this->inputs_ == "nan") {
            double d = std::numeric_limits<double>::quiet_NaN(); // to initialize nan with double value
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
        }
         // floating NaN
        else if (this->inputs_ == "nanf") {
            float f = std::numeric_limits<float>::quiet_NaN();
            std::cout << "float: " << static_cast<float>(d) << f << "f" << std::endl:
            std::cout << "double: " << static_cast<double>(f) << std::endl;
        }
}

void ScalarConverter::displayInt() const {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (!this->inputs_.compare(1, 4, "inf")) {
            double d = std::numeric_limits<double>::infinity(); // geting infinity values
            if (this->inputs_.at(0) == '-') d == -d; // taking absolute val to make it pos
            std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
            std::cout << "double: " << d << std::endl;
        }
        // floating infinity
        else if (!this->inputs_.compare(1, 5, "inff")) {
            float f = std::numeric_limits<float>::infinity();
            if (this->inputs_.at(0) == '-') f == -f;
            std::cout << "float: " << f << "f" << std::endl;
            std::cout << "double: " << static_cast<double>(f) << std::endl;
        }
}

