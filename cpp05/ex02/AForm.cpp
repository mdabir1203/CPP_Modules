/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:16:50 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/24 03:03:35 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) : name(name),  Signed(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
    else if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    
}

Form::~Form() {}

const std::string Form::getName() const
{
    return (name);
}

bool Form::isSigned() const 
{
    return this->Signed;
}

int Form::getGradeToSign() const
{
    return (gradeToSign);
}

int Form::getGradeToExecute() const
{
    return (gradeToExecute);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > gradeToSign)
        throw GradeTooLowException();
    Signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low");
}


std::ostream	&operator<<(std::ostream &os, const Form &form)
{
	os << "[" << form.getName() << "]" << std::endl;
	os << "\t" << "signed : " << form.isSigned() << std::endl;
	os << "\t" << "grade needed to sign : " << form.getGradeToSign() << std::endl;
	os << "\t" << "grade needed to execute : " << form.getGradeToExecute() << std::endl;
	return (os);
};
