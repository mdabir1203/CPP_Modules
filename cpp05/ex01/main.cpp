/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabbas <mabbas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 00:16:41 by mabbas            #+#    #+#             */
/*   Updated: 2023/07/24 03:29:19 by mabbas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bureaucrat("Barbie", 0);
        Form form("Example Form", 50, 75);
        //Form form2("Example Form", 50, 130);

        std::cout << form << std::endl;
        form.beSigned(bureaucrat);

        std::cout << form << std::endl; // updated form
    }
    catch (const std::exception& e) {
        std::cerr << "An exception occurred: " << e.what() << std::endl;
    }

    return 0;
}