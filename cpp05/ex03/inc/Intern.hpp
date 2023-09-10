#ifndef INTERN_HPP
#define INTERN_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <iostream>
#include <string>

class Bureaucrat;
class AForm;

class Intern{
    public:
        // Canonical //
        Intern(void);
        Intern( const Intern &f );
        ~Intern();
        Intern &operator=(Intern const &rhs);

        AForm *makeForm(std::string form, std::string target);

        class UnknownFormException: public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
    };

#endif