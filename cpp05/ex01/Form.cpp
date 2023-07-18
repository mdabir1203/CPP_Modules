#include "Form.hpp"
#include "bureaucrat.hpp"

Form::Form(std::string name, int gradeRequiredToSign, int gradeRequiredToExecute) : name(name), signedOrUnsigned(false), gradeRequiredToSign(gradeRequiredToSign), gradeRequiredToExecute(gradeRequiredToExecute) : 
            name(name),gradeRequiredToSign(gradeToSign), gradeRequiredToExecute(gradeToExecute)
{
    if (gradeRequiredToSign < 1 || gradeRequiredToExecute < 1)
        throw Form::GradeTooHighException();
    else if (gradeRequiredToSign > 150 || gradeRequiredToExecute > 150)
    {
        throw Form::GradeTooLowException();
    } 
}

std::string Form::getName() const
{
    return (this->name);
}

bool Form::isSigned() const 
{
    return (this->Signed);
}

int Form::getGradeToExecute() const
{
    return (this->gradeRequiredToExecute);
}

void Form::beSigned(const Bureaucrat& b)
{
    if (b.getGrade() > this->gradeRequiredToSign)
        throw Form::GradeTooLowException();
    else
        this->Signed = true;
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
    os << "Form" << form.getName() << ", grade required to sign:" 
        << form.getGradeToSign() << ", grade required to execute"
        << form.getGradeToExecute();
        return os;
}
