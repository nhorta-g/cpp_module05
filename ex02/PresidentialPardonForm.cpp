/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:04:45 by nuno              #+#    #+#             */
/*   Updated: 2024/01/17 19:14:36 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "PresidentialPardonForm.hpp"

//default constructor
PresidentialPardonForm::PresidentialPardonForm( std::string target )
: AForm("PresidentialPardonForm", 72, 45), _target(target) {
	std::cout << "Robotomy Request constructor called." << std::endl;
}
//copy constructor
PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src )
: AForm("PresidentialPardonForm", src.getGradeToSign(), src.getGradeToExecute()), _target(src.getTarget()) {
	std::cout << "Robotomy Request copy constructor called." << std::endl;
}
//assignment operator overload
PresidentialPardonForm & PresidentialPardonForm::operator = ( PresidentialPardonForm const & rhs ) {
	this->_target = rhs.getTarget();
	return *this;
}
//destructor
PresidentialPardonForm::~PresidentialPardonForm( void ) {
	std::cout << "Robotomy Request destructor called." << std::endl;
}
std::string	PresidentialPardonForm::getTarget( void ) const {
	return this->_target;
}
//PUBLIC METHODS
void PresidentialPardonForm::execute( Bureaucrat const & executor ) const {

	if (checkRequirements(executor.getGrade())) {
		std::cout << this->_target <<" has been pardoned by Zaphod Beeblebrox" << std::endl;
	}
}