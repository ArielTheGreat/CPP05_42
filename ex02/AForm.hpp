#ifndef AFORM_HPP
#define AFORM_HPP

#include <string> 
class Bureaucrat;

class AForm
{
    private:
        const std::string name;
        bool isSigned;
        const int requiredGradeToSign;
	    const int requiredGradeToExecute;
    public:
        AForm();
        AForm(std::string const &name, int const &signGrade, int const &execGrade);
        ~AForm();
        const std::string getName() const;
        bool getSigned() const;
        int getRequiredGradeSign() const;
        int getRequiredGradeExecute() const;
        void beSigned(const Bureaucrat &bureaucrat);
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
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif