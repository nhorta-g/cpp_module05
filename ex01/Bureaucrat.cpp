#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150) {
    std::cout << "Bureaucrat created using default constructor called for " <<
	this->getName() << " with grade " << this->getGrade() << std::endl;
    return;
}

Bureaucrat::Bureaucrat(int grade): _name("default") {
	try
	{
		this->setGrade(grade);
		std::cout << "Bureaucrat created using user defined constructor with 1 params for "
		<< this->getName() << " with grade " << this->getGrade() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e) //top limit, so grade cannot be < 1
	{
		std::cerr << "\033[33m Constructing " << this->getName() << " failed: "
			<< e.what() << std::endl << "Grade not set to 1" << "\033[0m" << std::endl;
		this->setGrade(1);
	}
	catch(Bureaucrat::GradeTooLowException &e) //bottom limit, so grade cannot be > 150
	{
		std::cerr << "\033[33m Constructing " << this->getName() << " failed: "
			<< e.what() << std::endl << "Grade not set to 150" << "\033[0m" << std::endl;
		this->setGrade(150);
	}
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name){
	try
	{
		this->setGrade(grade);
		std::cout << "Bureaucrat created using user defined constructor with 2 params for "
		<< this->getName() << " with grade " << this->getGrade() << std::endl;
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "\033[33m Constructing " << this->getName() << " failed: " <<
			e.what() << std::endl << "Grade not set to 1" << "\033[0m" << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "\033[33m Constructing " << this->getName() << " failed: " <<
			e.what() << std::endl << "Grade not set to 150" << "\033[0m" << std::endl;
	}

}

//copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src.getName() + "_copy") {
	*this = src;
	std::cout << "Bureaucrat copy constructor called to copy" <<
		src.getName() << std::endl;
}

//assignment operator overload
Bureaucrat &Bureaucrat::operator = (const Bureaucrat &src) {
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this == &src)
		return (*this);
	this->_grade = src.getGrade();
		return (*this);
}

Bureaucrat::~Bureaucrat(void) {
	std::cout << "Bureaucrat named " << this->_name \
		<< " destroyed" << std::endl;
	return;
}

//GETTERS & SETTERS

std::string Bureaucrat::getName(void) const {
	return (this->_name);
}

size_t Bureaucrat::getGrade(void) const {
	return (this->_grade);
}

void Bureaucrat::setName(const std::string name) {
	this->_name = name;
}

void Bureaucrat::setGrade(int grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
}

//PUBLIC METHODS
void Bureaucrat::incrementGrade(void) {
	try
	{
		std::cout << "Trying to increment " << this->getName()
			<< "'s grade" << std::endl;
		this->setGrade(_grade - 1);
	}
	catch(Bureaucrat::GradeTooHighException &e)
	{
		std::cerr << "\033[33mIncrementing grade of "<< this->getName()
			<< " failed: " << e.what() << "\033[0m" << std::endl;
	}
}

void Bureaucrat::decrementGrade(void) {
	try
	{
		std::cout << "Trying to decrement " << this->getName()
			<< "'s grade" << std::endl;
		this->setGrade(_grade + 1);
	}
	catch(Bureaucrat::GradeTooLowException &e)
	{
		std::cerr << "\033[33mDecrementing grade of "<< this->getName()
			<< " failed: " << e.what() << "\033[0m" << std::endl;
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