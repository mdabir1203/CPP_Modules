#include "../inc/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    std::cout << "Default constructor called" << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : name(src.name), grade(src.grade)
{
    std::cout << "Copy constructor called" << std::endl;
    if (src.grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (src.grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
    std::cout << "Assignation operator called" << std::endl;
    if (this != &rhs)
    {
        if (rhs.grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (rhs.grade > 150)
            throw Bureaucrat::GradeTooLowException();
        grade = rhs.grade;
    }
    return *this;
}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

void Bureaucrat::incrementGrade()
{
    if (grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    grade--;
}

void Bureaucrat::decrementGrade()
{
    if (grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    grade++;
}

std::ostream	&operator<<( std::ostream &o, const Bureaucrat &b )
{
	o << "Bureaucrat: " << b.getName() << std::endl;
	o << "Grade: " << b.getGrade() << std::endl;
	return (o);
}


void Bureaucrat::signForm( AForm &f ) const
{
	try
	{
		f.beSigned(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << " " << this->getName() << " couldn't sign " << f.getName() << " because " << e.what() << '\n';
	}
}

void	Bureaucrat::executeForm( AForm &f ) const
{
	try
	{
		f.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
}
