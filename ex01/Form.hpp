#include <string> 
#include "Bureaucrat.hpp"

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int requiredGradeToSign;
	    const int requiredGradeToExecute;
    public:
        Form();
        Form(std::string const &name, int const &signGrade, int const &execGrade);
        ~Form();
        const std::string getName() const;
        bool getSigned() const;
        const int getRequiredGradeSign() const;
        const int getRequiredGradeExecute() const;
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

std::ostream& operator<<(std::ostream& os, const Form& form);