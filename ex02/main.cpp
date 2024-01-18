/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:02:59 by nuno              #+#    #+#             */
/*   Updated: 2024/01/17 17:26:41 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void) {
	try {
		std::cout << "\033[1;31m" << "SHRUBBERY CREATION TEST" << "\033[0m" << std::endl;
		std::cout << "\033[1;31m" << "-----------------------" << "\033[0m" << std::endl;

		Bureaucrat b3("lili", 140);

		std::cout << b3 << std::endl;

		ShrubberyCreationForm susu("sequoia");

		b3.signForm(susu);

		std::cout << susu << std::endl;

		b3.executeForm(susu);

		std::cout << std::endl;
		std::cout << "\033[1;31m" << "ROBOTOMYREQUESTFORM" << "\033[0m" << std::endl;
		std::cout << "\033[1;31m" << "-------------------" << "\033[0m" << std::endl;

		Bureaucrat b2("toto", 40);

		std::cout << b2 << std::endl;

		RobotomyRequestForm robot("Marvin");

		b2.signForm(robot);

		std::cout << robot << std::endl;

		b2.executeForm(robot);

		std::cout << std::endl;
		std::cout << "\033[1;31m" << "PRESIDENTIAL PARDON FORM TEST" << "\033[0m" << std::endl;
		std::cout << "\033[1;31m" << "-----------------------------" << "\033[0m" << std::endl;

		Bureaucrat b1("bubu", 30);

		std::cout << b1 << std::endl;

		PresidentialPardonForm pdForm("Ford");

		b1.signForm(pdForm);

		std::cout << pdForm << std::endl;

		b1.executeForm(pdForm);

		std::cout << std::endl;
		std::cout << "\033[1;31m" << "CALLING DESTRUCTORS" << "\033[0m" << std::endl;
		std::cout << "\033[1;31m" << "-------------------" << "\033[0m" << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}


	return 0;
}