/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 03:48:46 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/26 03:56:07 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45, target){}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& form)
{
    this->target = form.getTarget();
    Bureaucrat tempoCrat = Bureaucrat("temp1", 1);
    if (form.isSigned())
    {
        this->beSigned(tempoCrat);
    }
    return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (this->getSign())
        throw AForm::NotSignedException();
    else if (executor.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();

    std::cout << "Makes some drilling noises..." << std::endl;
    if (rand() < RAND_MAX / 2)
    {
        std::cout << this->getTarget() << "has been robotomized successfully !" << std::endl;
    }
    else
    {
        std::cout << "The robotomy failed for " << this->getTarget() << "." << std::endl;
    }
}