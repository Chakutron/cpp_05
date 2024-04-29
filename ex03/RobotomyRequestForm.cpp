#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _target("Unknown")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : Form(other), _target(other.getTarget())
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
    (void)other;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

std::string RobotomyRequestForm::getTarget() const
{
    return (_target);
}

void    RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    if (this->getSigned() == false)
        throw Form::NotSignedException();
    else if (executor.getGrade() > this->getExecuteGrade())
        throw Form::GradeTooLowException();
    srand(time(0));
    int nbr = rand() % 100;
    std::cout << VIOLET << " Drill Drill Drill !!! " << NC << std::endl;
    if (nbr >= 50)
        std::cout << LBLUE << " - " << BLUE << this->_target << LBLUE << " is ROBOTOMIZED!" << NC << std::endl;
    else if (nbr < 50)
        std::cout << LBLUE << " - ROBOTOMY failed on " << BLUE << this->_target << NC << std::endl;
}