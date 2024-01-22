/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:02:59 by nuno              #+#    #+#             */
/*   Updated: 2024/01/18 13:53:36 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void) {
	std::cout << std::endl;
	std::cout << "\033[1;31m" << "SHRUBBERY CREATION" << "\033[0m" << std::endl;
	std::cout << "\033[1;31m" << "------------------" << "\033[0m" << std::endl;
    AForm* scf;
    try {
        Intern someRandomIntern;
        scf = someRandomIntern.makeForm("Shrubbery creation", "home");

        Bureaucrat b1("jardineiro", 137);
        b1.signForm(*scf);
        b1.executeForm(*scf);
        delete scf;
    } catch (std::exception& e) {
        std::cout << "Failed because: " << e.what() << std::endl;
    }
	std::cout << std::endl;
	std::cout << "\033[1;31m" << "ROBOTOMYRE QUEST" << "\033[0m" << std::endl;
	std::cout << "\033[1;31m" << "----------------" << "\033[0m" << std::endl;

    AForm* rrf;
    try {
        Intern someRandomIntern;
        rrf = someRandomIntern.makeForm("Robotomy request", "Bender");

        Bureaucrat b1("DoctorRobotomizer", 45);
        b1.signForm(*rrf);
        b1.executeForm(*rrf);
        delete rrf;
    } catch (std::exception& e) {
        std::cout << "Failed because: " << e.what() << std::endl;
    }
	std::cout << std::endl;
	std::cout << "\033[1;31m" << "PRESIDENTIAL PARDON" << "\033[0m" << std::endl;
	std::cout << "\033[1;31m" << "-------------------" << "\033[0m" << std::endl;

    AForm* ppf;
    try {
        Intern someRandomIntern;
        ppf = someRandomIntern.makeForm("Presidential pardon", "condemned");

        Bureaucrat b1("Presidente", 5);
        b1.signForm(*ppf);
        b1.executeForm(*ppf);
        delete ppf;
    } catch (std::exception& e) {
        std::cout << "Failed because: " << e.what() << std::endl;
    }
    std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "\033[1;31m" << "WRONG NAME" << "\033[0m" << std::endl;
	std::cout << "\033[1;31m" << "----------" << "\033[0m" << std::endl;

    AForm* wrong;
    try {
        Intern someRandomIntern;
        wrong = someRandomIntern.makeForm("wrong", "BLABLABLA");

        Bureaucrat b1("burocrata", 1);
        b1.signForm(*wrong);
        b1.executeForm(*wrong);
        delete wrong;
    } catch (std::exception& e) {
        std::cout << "Failed because: " << e.what() << std::endl;
    }
}
