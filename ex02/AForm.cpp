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