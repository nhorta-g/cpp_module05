/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:24:33 by nuno              #+#    #+#             */
/*   Updated: 2024/01/17 18:39:30 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//default constructor
ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
: AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "Shrubbery constructor called." << std::endl;
}
//copy constructor
ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src )
: AForm("ShrubberyCreationForm", src.getGradeToSign(), src.getGradeToExecute()), _target(src.getTarget()) {
	std::cout << "Shrubbery copy constructor called." << std::endl;
}
//assignment operator overload
ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs ) {
	this->_target = rhs.getTarget();
	return *this;
}
//destructor
ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	std::cout << "Shrubbery destructor called." << std::endl;
}

std::string	ShrubberyCreationForm::getTarget( void ) const {
	return this->_target;
}
//PUBLIC METHODS
void ShrubberyCreationForm::execute( Bureaucrat const & executor ) const {
	if (checkRequirements(executor.getGrade())) {

		std::string fileName = this->_target + "_shrubbery.txt";

		std::ofstream file(fileName.c_str());

		file << "                                  # #### ####" << std::endl;
		file << "                                ### v/#|### |/####" << std::endl;
		file << "                               ##v/#/ v||/##/_/##/_#" << std::endl;
		file << "                             ###  v/###|/ v/ # ###" << std::endl;
		file << "                           ##_v_#v_v## | #/###_/_####" << std::endl;
		file << "                          ## #### # v #| /  #### ##/##" << std::endl;
		file << "                           __#_--###`  |{,###---###-~" << std::endl;
		file << "                                     v }{" << std::endl;
		file << "                                      }}{" << std::endl;
		file << "                                      }}{" << std::endl;
		file << "                                 ejm  {{}" << std::endl;
		file << "                                , -=-~{ .-^- _" << std::endl;
		file << "                                      `}" << std::endl;
		file << "                                       {" << std::endl;

		file.close();
	}
}