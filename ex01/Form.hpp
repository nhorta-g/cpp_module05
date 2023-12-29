/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuno <nuno@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:03:05 by nuno              #+#    #+#             */
/*   Updated: 2023/12/29 17:03:06 by nuno             ###   ########.fr       */
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
		Form(int gradeToSign, int gradeToExecute );	//user defined
		Form (const std::string name, int gradeToSign, int gradeToExecute); //user defined
		Form (const Form &src);						//copy constructor
		Form &operator = (const Form &src);			//assignment operator
		~Form (void);								//destructor

	//GETTERS & SETTERS
	std::string	getName(void) const;
	bool	getSigned(void) const;
	int		getGradeToSign(void) const;
	int		getGradeToExecute(void) const;
	void	setName(const std::string name);
	void	setSigned(bool signedStatus);
	void	setGradeToSign(int gradeToSign);
	void	setGradeToExecute(int gradeToExecute);

	//PUBLIC METHODS
	void	beSigned(const Bureaucrat &b);
	void	signForm(bool signedStatus);
};

#endif