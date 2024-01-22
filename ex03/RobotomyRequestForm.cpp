/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:27:31 by nuno              #+#    #+#             */
/*   Updated: 2024/01/17 19:14:22 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

//default constructor
RobotomyRequestForm::RobotomyRequestForm( std::string target )
: AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "Robotomy Request constructor called." << std::endl;
}
//copy constructor
RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src )
: AForm("RobotomyRequestForm", src.getGradeToSign(), src.getGradeToExecute()), _target(src.getTarget()) {
	std::cout << "Robotomy Request copy constructor called." << std::endl;
}
//assignment operator overload
RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs ) {
	this->_target = rhs.getTarget();
	return *this;
}
//destructor
RobotomyRequestForm::~RobotomyRequestForm( void ) {
	std::cout << "Robotomy Request destructor called." << std::endl;
}
std::string	RobotomyRequestForm::getTarget( void ) const {
	return this->_target;
}
//PUBLIC METHODS
void RobotomyRequestForm::execute( Bureaucrat const & executor ) const {
		static int num;

	if (checkRequirements(executor.getGrade())) {
		std::cout << "DRILLING NOISES!!!" << std::endl;
		if (num % 2 == 0)
			std::cout << this->_target << " has been robotomized successfully" << std::endl;
		else
			std::cerr << this->_target << " robotomization failed." << std::endl;
	}
}