/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:20:12 by nuno              #+#    #+#             */
/*   Updated: 2024/01/18 13:29:10 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

	Intern::Intern(void) {
		std::cout << "Intern created" << std::endl;
	}
	Intern::Intern(Intern const& src) {
		*this = src;
		std::cout << "Intern created from copy constructor" << std::endl;
	}
	Intern& Intern::operator = (Intern const &rhs) {
		(void)rhs;
		std::cout << "Intern created from assign operator constructor" << std::endl;
		return (*this);
	}
	Intern::~Intern(void) {
		std::cout << "Intern destroyed" << std::endl;
	}
	//Public member function
	AForm* Intern::makeForm(const std::string name, const std::string target) {
		int	i = 0;
		AForm* form = 0;
		std::string solution[3] = {"Presidential pardon", "Shrubbery creation", "Robotomy request"};
		while (i < 3 && solution[i].compare(name))
			i++;
		if (i == 0)
		try {
			form = new PresidentialPardonForm(target);
		} catch (std::bad_alloc& e) {
			throw e;

		} else if (i == 1)
		try {
			form = new ShrubberyCreationForm(target);
		} catch (std::bad_alloc& e) {
			throw e;
		} else if (i == 2)
		try {
			form = new RobotomyRequestForm(target);
		} catch (std::bad_alloc& e) {
			throw e;
		} else if (i == 3)
			throw Intern::FormNotFound();
		return (form);
	}
	//Exception
	const char* Intern::FormNotFound::what(void) const throw() {
		return "Invalid form name";
	}
