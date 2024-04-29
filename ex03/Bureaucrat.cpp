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

void    Bureaucrat::signForm(Form &form)
{
    try
    {
        form.beSigned(*this);
        std::cout << BLUE << this->_name << GREEN << " signed " << BLUE << form.getName() << NC << std::endl;
    }
    catch (Form::GradeTooLowException &e)
    {
        std::cout << BLUE << this->_name << RED << " couldn't sign " << BLUE << form.getName() << RED << " because: " << e.what() << NC << std::endl;
    }
}

void    Bureaucrat::executeForm(Form const &form) const
{
    try 
    {
        form.execute(*this);
        std::cout << BLUE << this->_name << GREEN << " executed " << BLUE << form.getName() << NC << std::endl;
        //std::cout << " and created file: " << GREEN << (form.getTarget() + "_shrubbery").c_str() << NC << " in the working directory" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << BLUE << this->_name << RED << " couldn't execute " << BLUE << form.getName() << RED << " because: " << e.what() << NC << std::endl;
    }
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