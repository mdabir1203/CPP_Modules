#ifndef SHRUBERRYCREATIONFORM_HPP
#define SHRUBERRYCREATIONFORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <iostream>
#include <string>
#include <fstream>


class Bureaucrat;
class AForm;

class ShrubberyCreationForm : public AForm{
    private:
        std::string target;
    public:
        // Canonical //
        ShrubberyCreationForm(void);
        ShrubberyCreationForm( const ShrubberyCreationForm &f );
        ~ShrubberyCreationForm();
        ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

        ShrubberyCreationForm(std::string target);
        void execute(Bureaucrat const & executor) const;
    };

#endif