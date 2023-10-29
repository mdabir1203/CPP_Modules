/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 16:45:12 by mabbas            #+#    #+#             */
/*   Updated: 2023/10/29 17:08:21 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"



RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(RPN const & src) {
    *this = src;
}

RPN & RPN::operator=(RPN const & copy) {
    if (this != &copy) {
        this->stack = copy.stack;
    }
    return *this;
}

// used stack container -> 
// -> Operands processing is in correct order  
// -> Without needing to know size of input expression 
// Benefits of stack -> simplified, efficiency , versatility
// Use cases :  function calls , expression evaluation, backtracking, undo/redo functionality
// [3, 4, 5] -> [3], [4,5] extracting top two elements
bool RPN::handle_operator(char op)
{
    if (stack.size() < 2)
    {
        std::cout << "Error" << std::endl;
        exit(1);
    }
    int b = stack.top();
    stack.pop();
    int a = stack.top();
    stack.pop();
    switch(op)
    {
        case '+':
            stack.push(a + b);
            break;
        case '-':
            stack.push(a - b);
            break;
        case '*':
            stack.push(a * b);
            break;
        case '/':
            stack.push(a / b);
            break;
        default:
            return false;
    }
    return true;
}


// -> Iterates over each character -> checks size of stack
// ->  push digits to stack -> when operator (do operations) 
// -> result printed to console if valid . if not error 

void RPN::add_data(std::string data)
{
    size_t i = 0;
    while (i < data.size())
    {
        char c = data[i];
        if (c == ' ')
        {
            i++;
            continue;
        }
        else if (isdigit(c))
        {
            stack.push(c - '0');
        }
        else if (handle_operator(c) == false)
        {
            std::cout << "Error" << std::endl;
            exit(1);
        }
        i++;
    }
    if (stack.size() == 1)
        std::cout << stack.top() << std::endl;
    else
    {
        std::cout << "Error" << std::endl;
        exit(1);
    }
}