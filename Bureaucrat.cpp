#include "Bureaucrat.hpp"

BUREAUCRAT::BUREAUCRAT(void) {
    std::cout << "Bureaucrat created using default constructor" << std::endl;
    return;
}

BUREAUCRAT::BUREAUCRAT(std::string name, int grade) {
    if (grade < 1)
        throw BUREAUCRAT::GradeTooHighException();
    else if (grade > 150)
        throw BUREAUCRAT::GradeTooLowException();
    else {
        this->_name = name;
        this->_grade = grade;
    }
    std::cout << "Bureaucrat named " << this->_name \
		<< " constructed" << std::endl;
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
