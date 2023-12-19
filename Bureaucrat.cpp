#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {
    std::cout << "Bureaucrat created using default constructor for " <<
		this->getName << " with name " << this->getGrade << std::endl;
    return;
}

Bureaucrat::Bureaucrat(int grade): _name("default") {
	std::cout << "Bureaucrat created using user defined constructor for " <<
		this->getName << " with grade " << this->getGrade << std::endl;
	try
	{
		this->setGrade(grade);
	}
	catch(Bureaucrat::GradeTooHighException &e) //top limit, so grade cannot be < 1
	{
		std::cerr << e.what() << std::endl;
		this->setGrade(1);
	}
	catch(Bureaucrat::GradeTooLowException &e) //bottom limit, so grade cannot be > 150
	{
		std::cerr << "\033[33m Constructing " << this->getName() << " failed: "
			<< e.what() << std::endl << "Grade not set to 150" << "\033[0m";
			this->setGrade(150);
	}
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name){
	std::cout << "Bureaucrat created using user defined constructor for " <<
		this->getName << " with grade " << this->getGrade << std::endl;
	try
	{
		this->setGrade(grade);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << e.what() << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "\033[33m Constructing " << e.what() <<
		this->getName() << " failed: " << e.what() << std::endl
			<< "Grade not set to 1" << "\033[0m";
	}

}

Bureaucrat::~Bureaucrat(void) {
    std::cout << "Bureaucrat named " << this->_name \
		<< " destroyed" << std::endl;
    return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) {
    this->_name = src._name;
    this->_grade = src._grade;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat &src) {
    this->_name = src._name;
    this->_grade = src._grade;
    return (*this);
}

//EXCEPTIONS

void Bureaucrat::GradeTooHighException(std::string name, int grade) {
	std::cout << "Bureaucrat named " << name <<
		" cannot have a grade of " \
		<< grade << " because it is too high" << std::endl;
	return;
}

//GETTERS & SETTERS

void Bureaucrat::setName(const std::string _name) {
    this->_name = _name
}
