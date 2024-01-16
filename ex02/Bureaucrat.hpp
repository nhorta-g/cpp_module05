/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:03:10 by nuno              #+#    #+#             */
/*   Updated: 2024/01/15 16:56:18 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat {

	private:
		std::string _name;
		int _grade;

	public:
		Bureaucrat (void);								//default
		Bureaucrat (const std::string name, int grade); //user defined
		Bureaucrat (Bureaucrat const &src); 			//copy constructor
		Bureaucrat &operator = (Bureaucrat const &src); //assignment operator
		~Bureaucrat (void);								//destructor
	//GETTERS
	std::string	getName(void) const;
	int		getGrade(void) const;
	//PUBLIC METHODS
	void		incrementGrade(void);
	void		decrementGrade(void);
	void		signForm(Form &form);
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
std::ostream &operator << (std::ostream &out, Bureaucrat const &a);
#endif