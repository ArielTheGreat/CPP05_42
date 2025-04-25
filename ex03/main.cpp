
#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	*a;
	Bureaucrat	*b;
	
	// Creating a Bureaucrats
	try {
		std::cout << "Creating a Bureaucrat with grade 1" << std::endl;
		a = new Bureaucrat("Bureaucrat 1", 1);
		std::cout << *a << std::endl;
		std::cout << "Creating a Bureaucrat with grade 150" << std::endl;
		b = new Bureaucrat("Bureaucrat 2", 150);
		std::cout << *b << std::endl;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	
	// Shrubbery Creation Form
	try {
		std::cout << "Creating a Shrubbery Creation Form with target \"home\"" << std::endl;
		ShrubberyCreationForm shrubbery("home");
		std::cout << shrubbery << std::endl;
		std::cout << "Signing the form with Bureaucrat 1" << std::endl;
		a->signForm(shrubbery);
		std::cout << shrubbery << std::endl;
		std::cout << "Executing the form with Bureaucrat 1" << std::endl;
		a->executeForm(shrubbery);
		std::cout << "Executing the form with Bureaucrat 2" << std::endl;
		b->executeForm(shrubbery);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// Robotomy Request Form
	try {
		std::cout << "Creating a Robotomy Request Form with target \"home\"" << std::endl;
		RobotomyRequestForm robotomy("home");
		std::cout << robotomy << std::endl;
		std::cout << "Signing the form with Bureaucrat 1" << std::endl;
		a->signForm(robotomy);
		std::cout << robotomy << std::endl;
		std::cout << "Executing the form with Bureaucrat 1" << std::endl;
		a->executeForm(robotomy);
		std::cout << "Executing the form with Bureaucrat 2" << std::endl;
		b->executeForm(robotomy);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	// Presidential Pardon Form
	try {
		std::cout << "Creating a Presidential Pardon Form with target \"home\"" << std::endl;
		PresidentialPardonForm presidential("home");
		std::cout << presidential << std::endl;
		std::cout << "Signing the form with Bureaucrat 1" << std::endl;
		a->signForm(presidential);
		std::cout << presidential << std::endl;
		std::cout << "Executing the form with Bureaucrat 1" << std::endl;
		a->executeForm(presidential);
		std::cout << "Executing the form with Bureaucrat 2" << std::endl;
		b->executeForm(presidential);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	
	// Deleting Bureaucrats
	delete a;
	delete b;
	return (0);
}