#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
    public:
        std::string getName();
        int getGrade();
        void incrementGrade();
        void decrementGrade();
};

#endif