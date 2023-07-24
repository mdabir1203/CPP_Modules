/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:16:56 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/24 03:02:16 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string	name;
        bool				Signed;
        const int			gradeToSign;
        const int			gradeToExecute;
        Form();
    public:
        Form(const std::string& name, const int gradeToSign, const int gradeToExecute);
        Form(const Form& copy);
        ~Form();
        Form& operator=(const Form& form);
        
        const std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool isSigned() const;
        void beSigned(const Bureaucrat& bureaucrat);
        
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

std::ostream &operator<<(std::ostream& os, const Form& form);

#endif