/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 03:56:58 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/26 04:19:19 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy): AForm(copy), target(copy._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form) 
{
    this->target = form.getTarget();
    Bureaucrat tempoCrat = Bureaucrat("temp", 1);
    if (form.isSigned())
    {
        this->beSigned(tempoCrat);
    }
    return (*this);    
}





void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
    if (this->AForm::isSigned() == false)
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
        
    std::string filename = this->target + "_shrubbery";
    
    std::ofstream outputfile(filename);
    if (!outputfile)
    {
        throw FileOpenErrorException();
    }
    
    outputfile  << "          .         " << std::endl;
    outputfile  << "          .         " << std::endl;
    outputfile  << "       \\/|\\         " << std::endl; 
    outputfile  << "        / | \\        " << std::endl;  
    outputfile  << "     \\/ / \\ \\       " << std::endl;
    
    outputfile.close();
}