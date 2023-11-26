#include "Bureaucrat.hpp"

BUREAUCRAT::BUREAUCRAT(void) {
    std::cout << "Bureaucrat named " << this->_name \
		<< " created using default constructor" << std::endl;
    return;
}

BUREAUCRAT::~BUREAUCRAT(void) {
    std::cout << "Bureaucrat named " << this->_name \
		<< " destroyed" << std::endl;
    return;
}

BUREAUCRAT::BUREAUCRAT(const BUREAUCRAT &copy) {
    this->_name = copy._name;
    this->_grade = copy._grade;
}

BUREAUCRAT& BUREAUCRAT::operator = (const BUREAUCRAT &copy) {
    this->_name = copy._name;
    this->_grade = copy._grade;
    return (*this);
}

//GETTERS & SETTERS

void BUREAUCRAT::setName(const std::string _name) {
    this->_name = _name;
}
