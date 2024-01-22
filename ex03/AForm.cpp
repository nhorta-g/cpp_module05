/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 12:25:56 by nuno              #+#    #+#             */
/*   Updated: 2024/01/16 17:57:38 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

//default constructor
AForm::AForm(void) : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
	std::cout << "AForm created using default constructor called for " <<
	this->getName() << " with grade to sign " << this->getGradeToSign() <<
	" and grade to execute " << this->getGradeToExecute() << std::endl;
}
//user defined constructor
AForm::AForm(std::string name, const int gradeToSign, const int gradeToExecute) : _name(name),
	_signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm created using user defined constructor with name " << this->getName() <<
		" and with grade to sign " << this->getGradeToSign() << " and grade to execute " <<
		this->getGradeToExecute() << " as parameters." << std::endl;
}
//copy constructor
AForm::AForm(AForm const &src): _name(src.getName() + "_copy") {
	*this = src;
	std::cout << "AForm copy constructor called to copy" <<
		src.getName() << std::endl;
}
//assignment operator overload
AForm &AForm::operator = (AForm const &src) {
	std::cout << "AForm assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->_signed = src.getSigned();
		return (*this);
}
//destructor
AForm::~AForm(void) {
	std::cout << "AForm named " << this->_name \
		<< " destroyed" << std::endl;
}
//GETTERS & SETTERS
std::string AForm::getName(void) const {
	return (this->_name);
}
bool AForm::getSigned(void) const {
	return (this->_signed);
}
int AForm::getGradeToSign(void) const {
	return (this->_gradeToSign);
}
int AForm::getGradeToExecute(void) const {
	return (this->_gradeToExecute);
}
void AForm::setSigned(bool signedStatus) {
	this->_signed = signedStatus;
}
//PUBLIC METHODS
bool AForm::beSigned(const Bureaucrat &bureacrat) {
	if (bureacrat.getGrade() <= this->getGradeToSign()) {
		this->setSigned(true);
		return (true);
	}
	else
		throw AForm::GradeTooLowException();
}
bool AForm::checkRequirements(int grade) const {
	if (!getSigned()) {
		throw NotSignedExeption();
	} else if (grade > getGradeToExecute()) {
		throw GradeTooLowException();
	} else
		return true;
}
//EXCEPTIONS
const char *AForm::GradeTooHighException::what() const throw() {
	return ("Grade too high");
}
const char *AForm::GradeTooLowException::what() const throw() {
	return ("Grade too low");
}
const char *AForm::NotSignedExeption::what() const throw() {
	return ("Form Not signed");
}
//Ostream overload
std::ostream &operator << (std::ostream &out, const AForm &form) {
	out << form.getName() << ", status " << form.getSigned() << ", require grade: "
		<< form.getGradeToSign() << " and to execute " << form.getGradeToExecute();
	return (out);
}