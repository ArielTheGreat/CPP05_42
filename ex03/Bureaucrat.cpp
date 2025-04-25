#include "./Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

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

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name) , grade(other.grade)
{
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    if(this != &other){
		grade = other.grade;
	}
	return *this;
}

const std::string Bureaucrat::getName() const
{
    return (name);
}

int Bureaucrat::getGrade() const
{
    return (grade);
}

/* Decrementing because 1 is the highest grade*/
void Bureaucrat::incrementGrade()
{
    if(grade <= 1)
    {
		throw GradeTooHighException();
	}
    grade--;
}

/* Ading because 150 is the lowest grade*/
void Bureaucrat::decrementGrade()
{
    if(grade >= 150)
    {
		throw GradeTooLowException();
	}
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

Bureaucrat::~Bureaucrat(){}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return (os);
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signs " << form.getName() << std::endl;
    }catch(std::exception &e)
    {
        std::cout << name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void	Bureaucrat::executeForm(AForm const &form) const
{
	try {
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << this->name << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
	}
}