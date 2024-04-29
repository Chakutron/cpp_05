#include "AForm.hpp"

Form::Form() : _name("Blank form"), _signed(false), _signGrade(150), _executeGrade(150)
{
}

Form::Form(std::string const &name, int signGrade, int executeGrade) : _name(name), _signed(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
    this->verify(signGrade);
    this->verify(executeGrade);
}

Form::Form(Form const &other) : _name(other.getName()), _signed(other.getSigned()), _signGrade(other.getSignGrade()), _executeGrade(other.getExecuteGrade())
{
    *this = other;
}

Form &Form::operator=(Form const &other)
{
    this->verify(other.getSignGrade());
    this->verify(other.getExecuteGrade());
    return (*this);
}

Form::~Form()
{

}

std::string Form::getName() const
{
    return (this->_name);
}

bool    Form::getSigned() const
{
    return (this->_signed);
}

int Form::getSignGrade() const
{
    return (this->_signGrade);
}

int Form::getExecuteGrade() const
{
    return (this->_executeGrade);
}

void    Form::verify(int grade)
{
    if (grade < 1)
        throw Form::GradeTooHighException();
    if (grade > 150)
        throw  Form::GradeTooLowException();
}

void    Form::beSigned(Bureaucrat const &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_signGrade)
        throw Form::GradeTooLowException();
    this->_signed = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

const char *Form::NotSignedException::what() const throw()
{
    return ("Form not signed");
}

std::ostream    &operator<<(std::ostream &os, Form const &other)
{
    os << "***** " << BLUE << other.getName() << NC << " *****" << std::endl;
    if (other.getSigned())
        os << "- Is signed: " << GREEN << "YES" << NC << std::endl;
    else
        os << "- Is signed: " << RED << "NO" << NC << std::endl;
    os << "- Sign grade required: " << GREEN << other.getSignGrade() << NC << std::endl;
    os << "- Execution grade required: " << GREEN << other.getExecuteGrade() << NC << std::endl;
    os << "- Target: " << GREEN << other.getTarget() << NC;
    return (os);
}