#include <iostream>
#include "bureaucrat.hpp"

/**
 * Used more concise way of try and catch 
 * block */
int main() {
    try {
        Bureaucrat bob("Bob", 50);
        std::cout << bob << std::endl;
        bob.incrementGrade();
        std::cout << bob << std::endl;
        bob.decrementGrade();
        std::cout << bob << std::endl;
        Bureaucrat alice("Alice", 0);
        std::cout << alice << std::endl;
    }
    
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat charlie("Charlie", 151);
    } catch (Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
