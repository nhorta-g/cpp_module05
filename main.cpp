#include "Bureaucrat.hpp"

int main (void) {
	Bureaucrat a("Nuno", 1);	//should not throw exception
	Bureaucrat b("Nuno", 149);	//should not throw exception
	Bureaucrat c("Nuno", 150);	//should throw exception
	Bureaucrat d("Nuno", 151);	//should throw exception
	Bureaucrat e("Nuno", 0);	//should throw exception
	Bureaucrat f("Nuno", -1);	//should throw exception
	return (0);
}