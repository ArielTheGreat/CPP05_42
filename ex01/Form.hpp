#include <string> 

class Form
{
    private:
        const std::string name;
        bool isSigned;
        const int requiredGradeToSign;
	    const int requiredGradeToExecute;
    public:
        Form();
        ~Form();
        const std::string getName();
        bool getSigned();
        const int getRequiredGradeSign();
        const int getRequiredGradeExecute();
};