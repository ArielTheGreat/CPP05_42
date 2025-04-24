#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>

class PresidentialPardonForm : AForm
{
    private:
        std::string	_target;
    public:
        PresidentialPardonForm(void);
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &src);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &op);
        ~PresidentialPardonForm(void);

        void	execute(Bureaucrat const &executor) const;
        
        std::string	getTarget(void) const;
};

#endif