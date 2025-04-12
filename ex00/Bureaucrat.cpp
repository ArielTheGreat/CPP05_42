#include "./Bureaucrat.hpp"


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
