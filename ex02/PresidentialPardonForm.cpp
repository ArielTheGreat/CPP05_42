#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
{
	_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :
	AForm("PresidentialPardonForm", 25, 5)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :
	AForm(src)
{
	_target = src._target;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
	{
		this->_target = rhs._target;
		AForm::operator=(rhs);
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) { }

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	try {
		checkRequirements(executor);
		std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}

std::ostream	&operator<<(std::ostream &out, PresidentialPardonForm const &src)
{
	out << src.getName() << " is " << (src.getIsSigned() ? "" : "not ") << "signed." << std::endl;
	return (out);
}

std::string	PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}