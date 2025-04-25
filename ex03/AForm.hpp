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
    protected:
		void	checkRequirements(Bureaucrat const &bureaucrat) const;
    public:
        AForm();
        AForm(std::string const &name, int const &signGrade, int const &execGrade);
        ~AForm();
        const std::string getName() const;
        AForm &operator=(const AForm &rhs);
        AForm(const AForm &src);
        bool getSigned() const;
        int getRequiredGradeSign() const;
        int getRequiredGradeExecute() const;
        void beSigned(const Bureaucrat &bureaucrat);
        // Pure virtual functions
		virtual void	execute(Bureaucrat const & executor) const = 0;
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

        class UnsignedFormException : public std::exception
		{
			public:
				const char	*what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif