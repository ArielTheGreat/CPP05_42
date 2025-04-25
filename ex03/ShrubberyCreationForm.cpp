#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = "default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137)
{
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src)
{
	this->_target = src._target;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
		AForm::operator=(rhs);
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) { }


void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try {
		checkRequirements(executor);
		std::string		filename = getTarget() + "_shrubbery";
		std::fstream file(filename.c_str(), std::fstream::out | std::fstream::trunc);
		if (file.is_open()) {
			christmasTree(file);
			file.close();
		} else {
			std::cerr << "Error opening file" << std::endl;
		}
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm const &src)
{
	out << src.getName() << " is " << (src.getSigned() ? "" : "not ") << "signed." << std::endl;
	return (out);
}

std::string	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

void	ShrubberyCreationForm::christmasTree(std::ostream &ofs) const
{
	ofs
	<< std::endl
	<< "         #" << std::endl
	<< "        ***" << std::endl
	<< "       *#*O*" << std::endl
	<< "      **O****" << std::endl
	<< "     *#**O****" << std::endl
	<< "    *O*#**O**#**" << std::endl
	<< "   *#**O*#**#****" << std::endl
	<< "  ***O*#*O****O*#*" << std::endl
	<< " **O#**O**#*O**#***" << std::endl
	<< "       | o  |" << std::endl
	<< "       |  o |" << std::endl;
}