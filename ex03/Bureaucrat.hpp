#pragma once

#include <string>
#include <iostream>
#include "AForm.hpp"

#define RED "\e[31m"
#define GREEN "\e[32m"
#define YELLOW "\e[33m"
#define BLUE "\e[34m"
#define VIOLET "\e[35m"
#define LBLUE "\e[36m"
#define NC "\e[0m"

class Form;

class Bureaucrat
{
    public:
		// *** Orthodox Canonical Form ***
        Bureaucrat();
        Bureaucrat(std::string const &name, int grade);
        Bureaucrat(Bureaucrat const &other);
        Bureaucrat &operator=(Bureaucrat const &other);
        ~Bureaucrat();
		// *******************************
        std::string getName() const;
        int         getGrade() const;
        void        incrementGrade();
        void        decrementGrade();
        void        verify(int grade);
        void        signForm(Form &form);
        void        executeForm(Form const &form) const;
		// *** Exception nested classes ***
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
		// ********************************
    private:
        std::string const   _name;
        int                 _grade;
};

std::ostream    &operator<<(std::ostream &os, Bureaucrat const &other);