#include "Intern.hpp"

Intern::Intern()
{
    // Constructor
}

Intern::Intern(Intern const &other)
{
    *this = other;
}
Intern &Intern::operator=(Intern const &other)
{
    (void)other;
    return (*this);
}

Intern::~Intern()
{
}

Form    *Intern::makeForm(std::string name, std::string target)
{
    std::string names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    Form    *form;
    int     i;

    i = 0;
    while (i < 3)
    {
        if (name == names[i])
            break;
        i++;
    }

    switch (i)
    {
        case 0:
            form = new ShrubberyCreationForm(target);
            break;
        case 1:
            form = new RobotomyRequestForm(target);
            break;
        case 2:
            form = new PresidentialPardonForm(target);
            break;    
        default:
            std::cout << LBLUE << " - Intern cannot create " << BLUE << name << LBLUE << " form" << NC << std::endl;
            throw Intern::InvalidForm();
            break;
    }
    std::cout << LBLUE << " - Intern creates " << BLUE << name << LBLUE << " form" << NC << std::endl;
    
    return (form);
}

const char *Intern::InvalidForm::what() const throw()
{
    return ("Invalid form");
}
