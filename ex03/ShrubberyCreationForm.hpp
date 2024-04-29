#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
    public:
		// *** Orthodox Canonical Form ***
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string const &target);
        ShrubberyCreationForm(const ShrubberyCreationForm&other);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();
		// *******************************
        std::string getTarget() const;
        void        execute(Bureaucrat const &executor) const;
    private:
        std::string const   _target;
};