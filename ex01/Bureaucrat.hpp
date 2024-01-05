/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:03:10 by nuno              #+#    #+#             */
/*   Updated: 2024/01/04 20:12:03 by nuno             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
# define Bureaucrat_HPP

# include <string>
# include <iostream>
# include "Form.hpp"

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
	size_t		getGrade(void) const;
	//PUBLIC METHODS
	void		incrementGrade(void);
	void		decrementGrade(void);
	void		signForm(const Form &form);
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