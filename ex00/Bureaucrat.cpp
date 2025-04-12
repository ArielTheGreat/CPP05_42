#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Undefined"), grade(150) {}

Bureaucrat::Bureaucrat(const std::string p_name, int p_grade) : name(p_name)
{
    if (p_grade < 1)
    {
        throw GradeTooHighException();
    }else if(p_grade > 150)
    {
        throw GradeTooLowException();
    }
    grade = p_grade;
}

std::string Bureaucrat::getName()
{
    return (name);
}

int Bureaucrat::getGrade()
{
    return (grade);
}

/* Decrementing because 1 is the highest grade*/
void Bureaucrat::incrementGrade()
{
    grade--;
}

/* Ading because 150 is the lowest grade*/
void Bureaucrat::decrementGrade()
{
    grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
    return "Grade given is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
    return "Grade given is too low!";
}
