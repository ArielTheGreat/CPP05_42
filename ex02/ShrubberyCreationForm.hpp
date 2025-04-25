#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string	_target;
		void		christmasTree(std::ostream &ofs) const;

	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &op);
		~ShrubberyCreationForm(void);

		virtual void	execute(Bureaucrat const &executor) const;

		std::string	getTarget(void) const;

};

std::ostream	&operator<<(std::ostream &out, ShrubberyCreationForm const &src);

#endif