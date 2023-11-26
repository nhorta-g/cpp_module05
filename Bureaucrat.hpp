#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>

class BUREAUCRAT {
	public:
		BUREAUCRAT (void);
		BUREAUCRAT (std::string name, int grade);
		BUREAUCRAT (const BUREAUCRAT &copy);
		BUREAUCRAT &operator = (const BUREAUCRAT &copy);
		~BUREAUCRAT (void);
	
	void setName(const std::string _name);

	private:
		std::string _name;
		int _grade;
};
#endif