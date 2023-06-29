/**
 * no refences to references
 * req to initialiaze to refer to a valid obj / fnc
 * no ref to void
 * & -> lref && -> rref
 */

#include <iostream>

int main(void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string *stringPTR = &string;
    std::string &stringRef = string;

    std::cout << "address of string: " << &string << std::endl;
    std::cout << "address of pointer to string: " << stringPTR << std::endl;
    std::cout << "address of reference to string: " << &stringRef << std::endl;
    std::cout << "value of string pointer: " << *stringPTR << std::endl;
    std::cout << "value of string reference: " << stringRef << std::endl;

}
