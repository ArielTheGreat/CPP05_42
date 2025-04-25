#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

const std::string AForm::getName() const
{
    return (name);
}

bool AForm::getSigned() const
{
    return (isSigned);
}

AForm::AForm(const AForm &src) :
	name(src.name), requiredGradeToExecute(src.requiredGradeToExecute), requiredGradeToSign(src.requiredGradeToSign), isSigned(src.isSigned) { }

AForm &AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
		this->isSigned = rhs.isSigned;
	return (*this);
}

const char	*AForm::UnsignedFormException::what() const throw()
{
	return ("Form is not signed");
}

void	AForm::checkRequirements(Bureaucrat const &bureaucrat) const
{
	if (bureaucrat.getGrade() > this->requiredGradeToExecute)
		throw GradeTooLowException();
	if (!this->isSigned)
		throw UnsignedFormException();
}

int AForm::getRequiredGradeSign() const
{
    return (requiredGradeToSign);
}

int AForm::getRequiredGradeExecute() const
{
    return (requiredGradeToExecute);
}

AForm::AForm() : name("Undefined"), isSigned(false), requiredGradeToSign(75), requiredGradeToExecute(10) {}

AForm::AForm(std::string const &name, int const &signGrade, int const &execGrade) : name(name), isSigned(false), requiredGradeToSign(signGrade), requiredGradeToExecute(execGrade)
{
    if (requiredGradeToSign < 1)
		throw (AForm::GradeTooHighException());
	else if (requiredGradeToSign > 150)
		throw (AForm::GradeTooLowException());
	if (requiredGradeToExecute < 1)
		throw (AForm::GradeTooHighException());
	else if (requiredGradeToExecute > 150)
		throw (AForm::GradeTooLowException());
}

AForm::~AForm(){}

const char* AForm::GradeTooHighException::what() const noexcept
{
    return "Form error: Grade too high!";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
    return "Form error: Grade too low!";
}

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
    os << "Form: " << form.getName()
	<< "\nStatus: " << (form.getSigned() ? "SIGNED" : "UNSIGNED")
	<< "\nSign Grade: " << form.getRequiredGradeSign()
	<< "\nExecute Grade: " << form.getRequiredGradeExecute();
    return (os);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getRequiredGradeSign())
    {
        throw (AForm::GradeTooLowException());
    }
    isSigned = true;
}