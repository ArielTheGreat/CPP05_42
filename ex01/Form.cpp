#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

const std::string Form::getName() const
{
    return (name);
}

bool Form::getSigned() const
{
    return (isSigned);
}

int Form::getRequiredGradeSign() const
{
    return (requiredGradeToSign);
}

int Form::getRequiredGradeExecute() const
{
    return (requiredGradeToExecute);
}

Form::Form() : name("Undefined"), isSigned(false), requiredGradeToSign(75), requiredGradeToExecute(10) {}

Form::Form(std::string const &name, int const &signGrade, int const &execGrade) : name(name), isSigned(false), requiredGradeToSign(signGrade), requiredGradeToExecute(execGrade)
{
    if (requiredGradeToSign < 1)
		throw (Form::GradeTooHighException());
	else if (requiredGradeToSign > 150)
		throw (Form::GradeTooLowException());
	if (requiredGradeToExecute < 1)
		throw (Form::GradeTooHighException());
	else if (requiredGradeToExecute > 150)
		throw (Form::GradeTooLowException());
}

Form::~Form(){}

const char* Form::GradeTooHighException::what() const noexcept
{
    return "Form error: Grade too high!";
}

const char* Form::GradeTooLowException::what() const noexcept
{
    return "Form error: Grade too low!";
}

std::ostream& operator<<(std::ostream& os, const Form& form)
{
    os << "Form: " << form.getName()
	<< "\nStatus: " << (form.getSigned() ? "SIGNED" : "UNSIGNED")
	<< "\nSign Grade: " << form.getRequiredGradeSign()
	<< "\nExecute Grade: " << form.getRequiredGradeExecute();
    return (os);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getRequiredGradeSign())
    {
        throw (Form::GradeTooLowException());
    }
    isSigned = true;
}

Form::Form(const Form& other) : name(other.getName()), isSigned(other.getSigned()), requiredGradeToSign(other.getRequiredGradeSign()), requiredGradeToExecute(other.getRequiredGradeExecute())
{}

Form& Form::operator=(const Form& other)
{
    if(this != &other){
        isSigned = other.getSigned();
	}
	return *this;
}