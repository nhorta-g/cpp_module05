#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

# include <string>
# include <iostream>

class Bureaucrat {

	private:
		std::string _name;
		int _grade;

	public:
		Bureaucrat (void);					//default
		Bureaucrat(int grade );				//user defined
		Bureaucrat (const std::string name, int grade); //user defined
		Bureaucrat (const Bureaucrat &src); //copy constructor
		Bureaucrat &operator = (const Bureaucrat &src); //destructor
		~Bureaucrat (void);

	//Public methods
	void	incrementGrade(void);
	void	decrementGrade(void);

	//Getters
	std::string	getName(void) const;
	int	getGrade(void) const;

	//Exceptions
	class GradeTooHighException : public std::exception {
		public:
			const char *what() const throw();
	};

	class GradeTooLowException : public std::exception {
		public:
			const char *what() const throw();
	};
};

//Ostream overload

std::ostream &operator << (std::ostream &out,
	Bureaucrat const &bureaucrat);
#endif