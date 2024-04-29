#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
    this->verify(grade);
    this->_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &other)
{
    *this = other;
}

Bureaucrat  &Bureaucrat::operator=(Bureaucrat const &other)
{
    this->verify(other.getGrade());
    this->_grade = other.getGrade();
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
}

std::string Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void    Bureaucrat::incrementGrade()
{
    this->verify(this->_grade - 1);
    this->_grade--;
}

void    Bureaucrat::decrementGrade()
{
    this->verify(this->_grade + 1);
    this->_grade++;
}

void    Bureaucrat::verify(int grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw  Bureaucrat::GradeTooLowException();
}

const char  *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high");
}

const char  *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low");
}

std::ostream    &operator<<(std::ostream &os, Bureaucrat const &other)
{
    os << BLUE << other.getName() << NC << ", bureaucrat grade " << GREEN << other.getGrade() << NC;
    return (os);
}