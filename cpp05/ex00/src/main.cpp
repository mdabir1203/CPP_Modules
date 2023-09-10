#include "../inc/Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat	joe = Bureaucrat("Kean", 1);
		std::cout << joe << std::endl;
		joe.decrementGrade();
		std::cout << joe << std::endl;
		joe.incrementGrade();
		std::cout << joe << std::endl;
		joe.incrementGrade();
		std::cout << joe << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		Bureaucrat		jack = Bureaucrat("Roy", 150);
		std::cout << jack << std::endl;
		jack.incrementGrade();
		std::cout << jack << std::endl;
		jack.decrementGrade();
		std::cout << jack << std::endl;
		jack.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		Bureaucrat		john = Bureaucrat("Robin", 0);
		std::cout << john << std::endl;
		john.decrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;


	try
	{
		Bureaucrat		jillian = Bureaucrat("Cook", 151);
		std::cout << jillian << std::endl;
		jillian.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}