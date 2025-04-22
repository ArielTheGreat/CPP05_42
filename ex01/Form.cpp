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