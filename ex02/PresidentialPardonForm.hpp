#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public Form
{
    public:
		// *** Orthodox Canonical Form ***
        PresidentialPardonForm();
        PresidentialPardonForm(std::string const &target);
        PresidentialPardonForm(const PresidentialPardonForm&other);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();
		// *******************************
        std::string getTarget() const;
        void        execute(Bureaucrat const &executor) const;
    private:
        std::string const   _target;
};