/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:01:33 by nuno              #+#    #+#             */
/*   Updated: 2024/01/17 15:12:17 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//default constructor
Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {
    std::cout << "Bureaucrat created using default constructor called for " <<
	this->getName() << " with grade " << this->getGrade() << std::endl;
}
//user defined constructor
Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade) {
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Bureaucrat created using user defined constructor with name "
		<< this->getName() << " and with grade " << this->getGrade() <<

		" as parameters." << std::endl;
}
//copy constructor
Bureaucrat::Bureaucrat(Bureaucrat const &src): _name(src.getName() + "_copy") {
	*this = src;
	std::cout << "Bureaucrat copy constructor called to copy " <<
		src.getName() << std::endl;
}
//assignment operator overload
Bureaucrat &Bureaucrat::operator = (Bureaucrat const &src) {
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->_grade = src._grade;
		return (*this);
}
//destructor
Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat named " << this->_name \
		<< " destroyed" << std::endl;
}
//GETTERS & SETTERS
std::string Bureaucrat::getName(void) const {
	return (this->_name);
}
int Bureaucrat::getGrade(void) const {
	return (this->_grade);
}
//PUBLIC METHODS
void Bureaucrat::incrementGrade(void) {
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}
void Bureaucrat::decrementGrade(void) {
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}
void Bureaucrat::signForm(AForm &form) {
	if (form.beSigned(*this))
		std::cout << this->getName() << " signed " << form.getName()
			<< std::endl;
	else {
		std::cout << this->getName() << " couldn't sign " << form.getName()
			<< " because ";
		throw Bureaucrat::GradeTooLowException();
	}
}
void Bureaucrat::executeForm(AForm const &form) {
	try {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl << std::endl;
	}
}
//EXCEPTIONS
const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}
const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}
//Ostream overload
std::ostream &operator << (std::ostream &out, Bureaucrat const &a) {
	out << a.getName() << ", bureaucrat grade " << a.getGrade() << ".";
	return (out);
}