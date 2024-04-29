#pragma once

#include "AForm.hpp"
#include <cstdlib>

class RobotomyRequestForm : public Form
{
    public:
		// *** Orthodox Canonical Form ***
        RobotomyRequestForm();
        RobotomyRequestForm(std::string const &target);
        RobotomyRequestForm(const RobotomyRequestForm&other);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();
		// *******************************
        std::string getTarget() const;
        void        execute(Bureaucrat const &executor) const;
    private:
        std::string const   _target;
};