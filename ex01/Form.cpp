#include "Form.hpp"
#include <iostream>

const std::string Form::getName() const
{
    return (name);
}

bool Form::getSigned() const
{
    return (isSigned);
}

const int Form::getRequiredGradeSign() const
{
    return (requiredGradeToSign);
}

const int Form::getRequiredGradeExecute() const
{
    return (requiredGradeToExecute);
}

Form::Form() : name("Undefined"), isSigned(false), requiredGradeToSign(75), requiredGradeToExecute(10) {}



Form::~Form(){}

const char* Form::GradeTooHighException::exception::what() const
{
    return "Form error: Grade too high!";
}

const char* Form::GradeTooLowException::exception::what() const
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
        GradeTooLowException();
    }
    isSigned = true;
}