#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string	name;
        bool				Signed;
        const int			gradeRequiredToSign;
        const int			gradeRequiredToExecute;
    public:
        Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute);
        Form(const Form& copy);
        ~Form();
        Form& operator=(const Form& op);
        std::string getName() const;
        bool isSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        void beSigned(const Bureaucrat& b);
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#endif