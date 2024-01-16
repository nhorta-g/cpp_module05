/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:02:59 by nuno              #+#    #+#             */
/*   Updated: 2024/01/16 18:03:00 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(void) {

	std::cout << "\033[1;31m" << "CREATING BUROCRATS" << "\033[0m" << std::endl;
	std::cout << "\033[1;31m" << "------------------" << "\033[0m" << std::endl;

	Bureaucrat a("Drunk notary", 1);
	Bureaucrat b("Energized accountant", 150);
	std::cout << b << std::endl;

	std::cout << std::endl;
	std::cout << "\033[1;31m" << "TESTING COPY CONSTRUCTOR" << "\033[0m" << std::endl;
	std::cout << "\033[1;31m" << "------------------------" << "\033[0m" << std::endl;

	Bureaucrat c(a);
	std::cout << c << std::endl;
	c.decrementGrade();
	std::cout << a << " ; " << c << std::endl;

	std::cout << std::endl;
	Bureaucrat d(b);
	std::cout << d << std::endl;
	d.incrementGrade();
	std::cout << b << "; " << d << std::endl;

	std::cout << std::endl;
	std::cout << "\033[1;31m" << "CREATING FORMS" << "\033[0m" << std::endl;
	std::cout << "\033[1;31m" << "--------------" << "\033[0m" << std::endl;

	try {
		Form g("Boring form", 4, 6);
		std::cout << g << std::endl << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl << std::endl;
	}
	try {
		Form g("Extensive form", 150, 5);
		std::cout << g << std::endl << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl << std::endl;
	}
	try {
		Form g("Complicated form", 0, 4);
		std::cout << g << std::endl << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl << std::endl;
	}
	try {
		Form g("Complex form", 1, 3);
		std::cout << g << std::endl << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl << std::endl;
	}
	try {
		Form g("Imposible to know how to fill form", 151, 2);
		std::cout << g << std::endl << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl << std::endl;
	}
	try {
		Form g("Another form", -1, 1);
		std::cout << g << std::endl << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl << std::endl;
	}
	try {
		Form g("And another form", 1, -5);
		std::cout << g << std::endl << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\033[1;31m" << "TESTING SIGNING" << "\033[0m" << std::endl;
	std::cout << "\033[1;31m" << "--------------" << "\033[0m" << std::endl;

	Bureaucrat johnny("Johnny", 75);
	try {
		Form f("test1", 80, 20);
		johnny.signForm(f);
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl << std::endl;
	}
	try {
		Form f("test2", 75, 20);
		johnny.signForm(f);
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl << std::endl;
	}
	try {
		Form f("test3", 54, 20);
		johnny.signForm(f);
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl << std::endl;
	}
	try {
		Form f("test4", 20, 20);
		johnny.signForm(f);
		std::cout << std::endl;
	}
	catch (std::exception& e) {
		std::cerr << e.what() << std::endl << std::endl;
	}

	std::cout << std::endl;
	std::cout << "\033[1;31m" << "CALLING DESTRUCTORS" << "\033[0m" << std::endl;
	std::cout << "\033[1;31m" << "-------------------" << "\033[0m" << std::endl;
	return(0);
}

