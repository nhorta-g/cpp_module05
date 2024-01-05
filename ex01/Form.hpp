/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:03:05 by nuno              #+#    #+#             */
/*   Updated: 2024/01/04 20:17:11 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>
# include "Bureaucrat.hpp"

class Form {

	private:
		std::string _name;
		bool _signed;
		int _gradeToSign;
		int _gradeToExecute;

	public:
		Form (void);								//default
		Form (const std::string name, int gradeToSign, int gradeToExecute); //user defined
		Form (const Form &src);						//copy constructor
		Form &operator = (const Form &src);			//assignment operator
		~Form (void);								//destructor
	//GETTERS
	std::string	getName(void) const;
	bool	getSigned(void) const;
	int		getGradeToSign(void) const;
	int		getGradeToExecute(void) const;
	//SETTERS
	void	setSigned(bool signedStatus);
	//PUBLIC METHODS
	void	beSigned(const Bureaucrat &b);
	//EXCEPTIONS
	class GradeTooHighException : public std::exception {
		public:
			const char *what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char *what() const throw();
	};
};

	//OSTREAM OVERLOAD
	std::ostream &operator<<(std::ostream &out, const Form &form);
#endif