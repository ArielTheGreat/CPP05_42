#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45)
{
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src)
{
	this->_target = src._target;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
		AForm::operator=(rhs);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) { }


void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	try {
		checkRequirements(executor);
		std::cout << "* [RobotomyRequestForm] *drilling noises* " << this->_target << " has been successfully robotomized 50\% of the time" << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &out, RobotomyRequestForm const &src)
{
	out << src.getName() << " is " << (src.getSigned() ? "" : "not ") << "signed." << std::endl;
	return (out);
}

std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}