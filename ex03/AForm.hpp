#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
		// *** Orthodox Canonical Form ***
        Form();
        Form(std::string const &name, int signGrade, int executeGrade);
        Form(Form const &other);
        Form &operator=(Form const &other);
        virtual ~Form();
		// *******************************
        std::string         getName() const;
        bool                getSigned() const;
        int                 getSignGrade() const;
        int                 getExecuteGrade() const;
        void                verify(int grade);
        void                beSigned(Bureaucrat const &bureaucrat);
        virtual void        execute(const Bureaucrat &executor) const = 0;
        virtual std::string getTarget() const = 0;
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
        class NotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };        
		// ********************************
    private:
        std::string const   _name;
        bool                _signed;
        int const           _signGrade;
        int const           _executeGrade;
};

std::ostream    &operator<<(std::ostream &os, Form const &other);