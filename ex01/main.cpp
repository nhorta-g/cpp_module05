#include "Bureaucrat.hpp"

int main (void) {

	std::cout << "\033[1;31m" << "TESTING BUREAUCRAT WITH 1 PARAMS" << "\033[0m" << std::endl;
	std::cout << "\033[1;31m" << "--------------------------------" << "\033[0m" << std::endl;
	std::cout << "\033[1;35m" << "Should not trigger exception" << "\033[0m" << std::endl;
	Bureaucrat a(1);
	Bureaucrat b(99);
	Bureaucrat c(150);
	std::cout << "\033[1;35m" << "Should trigger exception" << "\033[0m" << std::endl;
	Bureaucrat d(151);
	Bureaucrat e(0);
	Bureaucrat f(-1);

	std::cout << "\033[1;31m" << "TESTING BUREAUCRAT WITH 2 PARAMS" << "\033[0m" << std::endl;
	std::cout << "\033[1;31m" << "--------------------------------" << "\033[0m" << std::endl;
	std::cout << "\033[1;35m" << "Should not trigger exception" << "\033[0m" << std::endl;
	Bureaucrat g("Nuno", 1);
	Bureaucrat h("Nuno", 100);
	Bureaucrat i("Nuno", 150);
	std::cout << "\033[1;35m" << "Should trigger exception" << "\033[0m" << std::endl;
	Bureaucrat j("Nuno", 151);
	Bureaucrat k("Nuno", 0);
	Bureaucrat l("Nuno", -1);

	std::cout << "\033[1;31m" << "TESTING BUREAUCRAT COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR" << "\033[0m" << std::endl;
	std::cout << "\033[1;31m" << "--------------------------------------------------------" << "\033[0m" << std::endl;
	std::cout << "\033[1;35m" << "Should not trigger exception" << "\033[0m" << std::endl;
	Bureaucrat m = g;
	Bureaucrat n(h);
	std::cout << m << std::endl;
	std::cout << n << std::endl;
	std::cout << "\033[1;35m" << "Should trigger exception" << "\033[0m" << std::endl;
	Bureaucrat o("Nuno", 151);
	Bureaucrat p("Nuno", 0);
	Bureaucrat q("Nuno", -1);

	std::cout << "\033[1;31m" << "TESTING BUREAUCRAT INCREMENT AND DECREMENT" << "\033[0m" << std::endl;
	std::cout << "\033[1;31m" << "-----------------------------------------" << "\033[0m" << std::endl;
	std::cout << "\033[1;35m" << "Should not trigger exception" << "\033[0m" << std::endl;
	std::cout << "Before decrement: " << n << std::endl;
	n.decrementGrade();
	std::cout << "After decrement: " << n << std::endl;
	std::cout << "\033[1;35m" << "Should trigger exception" << "\033[0m" << std::endl;
	std::cout << "Before increment: " << i << std::endl;
	o.incrementGrade();
	std::cout << "After increment: " << i << std::endl;
	std::cout << "Before decrement: " << g << std::endl;
	p.decrementGrade();
	std::cout << "After decrement: " << g << std::endl;

	std::cout << "\033[1;31m" << "CALLING DESTRUCTORS" << "\033[0m" << std::endl;
	std::cout << "\033[1;35m" << "Should not trigger exception" << "\033[0m" << std::endl;
	return (0);
}