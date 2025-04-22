# include "Bureaucrat.hpp"
# include <iostream>

int main()
{
    try {
		Bureaucrat Rick("Rick", 150);
		std::cout << Rick << std::endl;
		Rick.decrementGrade();
		std::cout << Rick << std::endl;
	} catch (std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}

	std::cout << "--------------" << std::endl;

	try {
		Bureaucrat Morty("Morty", 1);
		std::cout << Morty << std::endl;
		Morty.incrementGrade();
		std::cout << Morty << std::endl;
	} catch (std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}

	std::cout << "--------------" << std::endl;

	try {
		Bureaucrat Summer("Summer", 149);
		std::cout << Summer << std::endl;
		Summer.decrementGrade();
		std::cout << Summer << std::endl;
	} catch (std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}

	std::cout << "--------------" << std::endl;

	try {
		Bureaucrat Jerry("Jerry", 149);
		std::cout << Jerry << std::endl;
		Jerry.incrementGrade();
		std::cout << Jerry << std::endl;
	} catch (std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}

	std::cout << "--------------" << std::endl;

	try {
		Bureaucrat Homer("Homer", 0);
		std::cout << Homer << std::endl;
		Homer.incrementGrade();
		std::cout << Homer << std::endl;
	} catch (std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}

	std::cout << "--------------" << std::endl;

	try {
		Bureaucrat Bart("Bart", 100000);
		std::cout << Bart << std::endl;
		Bart.incrementGrade();
		std::cout << Bart << std::endl;
	} catch (std::exception& e) {
		std::cerr << "EXCEPTION ERROR: " << e.what() << std::endl;
	}
    return (0);
}
