/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 03:14:04 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/26 03:46:05 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresedentialPardonForm::PresedentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5, target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy){}
PresedentialPardonForm::~PresedentialPardonForm(){return ;}

/**
 * assignment operator correctly handles the 
 * signing status of the  PresidentialPardonForm  object being assigned. 
 */
PresedentialPardonForm& PresedentialPardonForm:: operator=(const PresedentialPardonForm& form)
{
    this->target = form.getTarget();
    Bureaucrat tempoCrat = Bureaucrat("temp", 1);
    if (form.isSigned())
    {
        this->beSigned(tempoCrat);
    }
    return (*this);
}

void PresedentialPardonForm::execute(const Bureaucrat& executor) const
{
    if (this->AForm::isSigned() == false)
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
    else
        std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}