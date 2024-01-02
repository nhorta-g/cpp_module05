/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 20:00:14 by nuno              #+#    #+#             */
/*   Updated: 2023/12/29 16:40:40 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main (void) {
	std::cout << "\033[1;31m" << "TESTING BUREAUCRAT WITH 2 PARAMS" << "\033[0m" << std::endl;
	std::cout << "\033[1;31m" << "--------------------------------" << "\033[0m" << std::endl;
	std::cout << "\033[1;35m" << "Should not trigger exception" << "\033[0m" << std::endl;
	try
	{
		Bureaucrat a("Nuno", 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[1;35m" << "Should trigger exception" << "\033[0m" << std::endl;
	try
	{
		Bureaucrat b("Nuno", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
		try
	{
		Bureaucrat c("Nuno", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[1;31m" << "TESTING BUREAUCRAT INCREMENT AND DECREMENT" << "\033[0m" << std::endl;
	std::cout << "\033[1;31m" << "-----------------------------------------" << "\033[0m" << std::endl;
	std::cout << "\033[1;35m" << "Incrementing when at maximum grade" << "\033[0m" << std::endl;
	try {
		Bureaucrat d("Nuno", 1);
		std::cout << "Before increment: " << d << std::endl;
		d.incrementGrade();
		std::cout << "After increment: " << d << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[1;35m" << "Decrementing when at maximum grade" << "\033[0m" << std::endl;
	try {
		Bureaucrat e("Nuno", 150);
		std::cout << "Before increment: " << e << std::endl;
		e.decrementGrade();
		std::cout << "After increment: " << e << std::endl;
	}
	catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << "\033[1;31m" << "TESTING GENERAL BEHAVIER" << "\033[0m" << std::endl;
	std::cout << "\033[1;31m" << "-----------------------------------------" << "\033[0m" << std::endl;
	try
	{
		Bureaucrat Eu("Eu", 4);
		std::cout << Eu;
		Eu.incrementGrade();
		std::cout << Eu;
		for (int i = 0; i < 3; i++) {
			Eu.incrementGrade();
			std::cout << Eu << "[" << i << "] ";		}
		Eu.incrementGrade();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << "\033[1;31m" << "CALLING DESTRUCTORS" << "\033[0m" << std::endl;

	return (0);
}