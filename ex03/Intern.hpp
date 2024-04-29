#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
		// *** Orthodox Canonical Form ***
        Intern();
        Intern(Intern const &other);
        Intern &operator=(Intern const &other);
        ~Intern();
		// *******************************
        Form    *makeForm(std::string name, std::string target);
		// *** Exception nested classes ***
        class InvalidForm : public std::exception 
		{
            public:
                virtual const char *what() const throw();
        };
		// ********************************
};