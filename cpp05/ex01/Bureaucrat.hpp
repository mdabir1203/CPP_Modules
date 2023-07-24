/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 02:48:51 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/24 02:52:33 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		const std::string	    name;
		int					    grade;
        void   checkGrade(int grade);
	public:
        Bureaucrat();
        Bureaucrat(const std::string name, int grade);
        Bureaucrat(const Bureaucrat &copy);
        ~Bureaucrat();
        Bureaucrat& operator=(const Bureaucrat &assign);
        
        const std::string       getName() const;
        int                     getGrade() const;
        
        void                    incrementGrade();
        void                    decrementGrade();

        void                    signForm(Form &form);

        class GradeTooHighException : public std::exception
	    {
            public:
                const char	*what() const throw();
	    };
	    class GradeTooLowException : public std::exception
	    {  
            public:
                const char	*what() const throw();
	    };
};

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif