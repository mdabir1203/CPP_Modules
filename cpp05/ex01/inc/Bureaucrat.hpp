#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H

#include "Form.hpp"

#include <iostream>
#include <string>

class	Form;

class Bureaucrat
{
private:
    std::string const name;
    int grade;
public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &src);
    ~Bureaucrat();

    Bureaucrat &operator=(Bureaucrat const &rhs);

    std::string getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
	void signForm( Form &f ) const;

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade too high");
		}
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char* what() const throw()
		{
			return ("Grade is too low");
		}
	};
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif