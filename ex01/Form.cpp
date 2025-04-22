#include "Form.hpp"

const std::string Form::getName()
{
    return (name);
}

bool Form::getSigned()
{
    return (isSigned);
}

const int Form::getRequiredGradeSign()
{
    return (requiredGradeToSign);
}

const int Form::getRequiredGradeExecute()
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