/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:45:06 by mabbas            #+#    #+#             */
/*   Updated: 2023/10/29 16:54:07 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>

class RPN {
    private :
        std::stack<int> stack;
    public :
        RPN();
        ~RPN();
        RPN(RPN const & src);
        RPN &   operator=(RPN const & copy);
        void    add_data(std::string data);
        bool    handle_operator(char op);
};
#endif