/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:16:56 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/26 02:07:02 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        const std::string	name;
        bool				Signed;
        const int			gradeToSign;
        const int			gradeToExecute;
        AForm();
    public:
        AForm(const std::string& name, const int gradeToSign, const int gradeToExecute);
        AForm(const AForm& copy);
        virtual ~AForm();
        AForm& operator=(const Form& form);
        
        const std::string getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool isSigned() const;
        void beSigned(const Bureaucrat& bureaucrat);
        
        virtual void execute(const Bureaucrat& executor) const = 0;
        
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