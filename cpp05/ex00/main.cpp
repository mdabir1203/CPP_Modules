#include <iostream>
#include "bureaucrat.hpp"

/**
 * Used more concise way of try and catch 
 * block */
int main() {
    try {
        Bureaucrat merve("Merve", 150);
        std::cout << merve << std::endl;
        merve.incrementGrade();
        std::cout << merve << std::endl;
        merve.decrementGrade();
        std::cout << merve << std::endl;
        Bureaucrat click("Velma", 0);
        std::cout << click << std::endl;
    }
    
    catch (Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat random("Random", 151);
    } catch (Bureaucrat::GradeTooHighException& e) {
        std::cerr << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
