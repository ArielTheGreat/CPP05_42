#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
class AForm;

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        const std::string getName() const;
        int getGrade() const;
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        ~Bureaucrat();
        Bureaucrat(const Bureaucrat& other);
	    Bureaucrat& operator=(const Bureaucrat& other);
        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const noexcept override;
        };
        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const noexcept override;
        };
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm &form);
        void executeForm(AForm const &form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif