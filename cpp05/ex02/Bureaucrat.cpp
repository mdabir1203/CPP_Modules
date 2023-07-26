	/* ************************************************************************** */
	/*                                                                            */
	/*                                                        :::      ::::::::   */
	/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
	/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
	/*                                                +#+#+#+#+#+   +#+           */
	/*   Created: 2023/07/24 01:27:11 by mabbas            #+#    #+#             */
	/*   Updated: 2023/07/24 02:34:09 by mabbas           ###   ########.fr       */
	/*                                                                            */
	/* ************************************************************************** */

	#include "Bureaucrat.hpp"

	Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
	{
		checkGrade(grade);
	}
	Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) 
	{
		*this = bureaucrat;
	}
	Bureaucrat::~Bureaucrat() {return ;}
	Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &bureaucrat)
	{
		if (this != &bureaucrat)
		{
			this->grade = bureaucrat.grade;
		}
		return (*this);
	}

	const std::string Bureaucrat::getName() const {return (name);}
	int Bureaucrat::getGrade() const {return (grade);}

	void	Bureaucrat::incrementGrade(void)
	{
		if (grade - 1 < 1)
		{
			throw GradeTooHighException();
		}
		grade--;
	}

	void	Bureaucrat::decrementGrade(void)
	{
		if (grade + 1 >= 150)
		{
			throw GradeTooLowException();
		}
		grade++;
	}

	void Bureaucrat::checkGrade(int grade)
	{
		if (grade > 150)
		{ 
			throw GradeTooLowException();
		}
		else if (grade < 1)
		{
			throw GradeTooHighException();
		}
	}

	std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
	{
		out << bureaucrat.getName() << ", grade is: " << bureaucrat.getGrade();
		return (out);
	}

	void Bureaucrat::signForm(Form &form)
	{
		try
		{
			if (this->getGrade() <= form.getGradeToSign())
			{
				form.beSigned(*this);
				std::cout << this->name << " signed " << form.getName() << std::endl;
			}
			else
			{
				std::cout << this->name << " couldn't sign " << form.getName() << " because their grade is too high" << std::endl;
				throw GradeTooHighException();
			}
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl;	
		}
	}


	const char* Bureaucrat::GradeTooHighException::what() const throw()
	{
		return ("Grade is too high");
	}

	const char* Bureaucrat::GradeTooLowException::what() const throw()
	{
		return ("Grade is too low");
	}