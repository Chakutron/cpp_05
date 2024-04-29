#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), _target("Unknown")
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : Form(other), _target(other.getTarget())
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
    (void)other;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

std::string PresidentialPardonForm::getTarget() const
{
    return (_target);
}

void    PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    if (this->getSigned() == false)
        throw Form::NotSignedException();
    else if (executor.getGrade() > this->getExecuteGrade())
        throw Form::GradeTooLowException();
    std::cout << LBLUE << " - " << BLUE << this->_target << LBLUE << " has been pardoned by " << BLUE << "Zaphod Beeblebrox" << NC << std::endl;
}