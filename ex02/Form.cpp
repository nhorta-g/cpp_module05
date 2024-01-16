/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:25:56 by nuno              #+#    #+#             */
/*   Updated: 2024/01/16 17:57:38 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

//default constructor
Form::Form(void) : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "Form created using default constructor called for " <<
	this->getName() << " with grade to sign " << this->getGradeToSign() <<
	" and grade to execute " << this->getGradeToExecute() << std::endl;
}
//user defined constructor
Form::Form(std::string name, const int gradeToSign, const int gradeToExecute) : _name(name),
	_signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form created using user defined constructor with name " << this->getName() <<
		" and with grade to sign " << this->getGradeToSign() << " and grade to execute " <<
		this->getGradeToExecute() << " as parameters." << std::endl;
}
//copy constructor
Form::Form(Form const &src): _name(src.getName() + "_copy") {
	*this = src;
	std::cout << "Form copy constructor called to copy" <<
		src.getName() << std::endl;
}
//assignment operator overload
Form &Form::operator = (Form const &src) {
	std::cout << "Form assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->_signed = src.getSigned();
		return (*this);
}
//destructor
Form::~Form(void) {
	std::cout << "Form named " << this->_name \
		<< " destroyed" << std::endl;
}
//GETTERS & SETTERS
std::string Form::getName(void) const {
	return (this->_name);
}
bool Form::getSigned(void) const {
	return (this->_signed);
}
int Form::getGradeToSign(void) const {
	return (this->_gradeToSign);
}
int Form::getGradeToExecute(void) const {
	return (this->_gradeToExecute);
}
void Form::setSigned(bool signedStatus) {
	this->_signed = signedStatus;
}
//PUBLIC METHODS
bool Form::beSigned(const Bureaucrat &bureacrat) {
	if (bureacrat.getGrade() <= this->getGradeToSign()) {
		this->setSigned(true);
		return (true);
	}
	else
		throw Form::GradeTooLowException();
}
//EXCEPTIONS
const char *Form::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}
const char *Form::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}
//Ostream overload
std::ostream &operator << (std::ostream &out, const Form &form) {
	out << form.getName() << ", status " << form.getSigned() << ", require grade: "
		<< form.getGradeToSign() << " and to execute " << form.getGradeToExecute();
	return (out);
}