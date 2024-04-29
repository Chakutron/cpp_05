#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void) 
{
    std::cout << "------------------------------------------------" << std::endl;
  	{
        // ShrubberyCreationForm (145/137)
        Bureaucrat chaku("Chaku", 42);
        std::cout << chaku << std::endl;
        ShrubberyCreationForm form("Perpignan");
        std::cout << form << std::endl;
        std::cout << YELLOW << "Trying to sign the form.." << NC << std::endl;
        chaku.signForm(form);
        std::cout << form << std::endl;
        std::cout << YELLOW << "Trying to execute the form.." << NC << std::endl;
        chaku.executeForm(form);
    }
    std::cout << "------------------------------------------------" << std::endl;
  	{
        // RobotomyRequestForm (72/45)
        Bureaucrat chaku("Chaku", 42);
        std::cout << chaku << std::endl;
        RobotomyRequestForm form("Adriano");
        std::cout << form << std::endl;
        std::cout << YELLOW << "Trying to sign the form.." << NC << std::endl;
        chaku.signForm(form);
        std::cout << form << std::endl;
        std::cout << YELLOW << "Trying to execute the form.." << NC << std::endl;
        chaku.executeForm(form);
    }
    std::cout << "------------------------------------------------" << std::endl;
  	{
        // PresidentialPardonForm (25/5)
        Bureaucrat theouche("Theouche", 1);
        std::cout << theouche << std::endl;
        PresidentialPardonForm form("Adriano");
        std::cout << form << std::endl;
        std::cout << YELLOW << "Trying to sign the form.." << NC << std::endl;
        theouche.signForm(form);
        std::cout << form << std::endl;
        std::cout << YELLOW << "Trying to execute the form.." << NC << std::endl;
        theouche.executeForm(form);
    }
}