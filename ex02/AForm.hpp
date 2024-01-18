/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:03:05 by nuno              #+#    #+#             */
/*   Updated: 2024/01/17 19:23:09 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

	private:
		std::string _name;
		bool _signed;
		int _gradeToSign;
		int _gradeToExecute;

	public:
		AForm (void);								//default
		AForm (const std::string name, int gradeToSign, int gradeToExecute); //user defined
		AForm (const AForm &src);						//copy constructor
		AForm &operator = (const AForm &src);			//assignment operator
		~AForm (void);								//destructor
	//GETTERS
	std::string	getName(void) const;
	bool	getSigned(void) const;
	int		getGradeToSign(void) const;
	int		getGradeToExecute(void) const;
	//SETTERS
	void	setSigned(bool signedStatus);
	//PUBLIC METHODS
	bool	beSigned(const Bureaucrat &b);
	bool	checkRequirements( int grade ) const;
	virtual void execute(Bureaucrat const & executor) const = 0;
	//EXCEPTIONS
	class GradeTooHighException : public std::exception {
		public:
			const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char *what() const throw();
	};
	class NotSignedExeption : public std::exception {
		public:
			const char *what() const throw();
	};
};
	//OSTREAM OVERLOAD
	std::ostream &operator<<(std::ostream &out, const AForm &form);
#endif