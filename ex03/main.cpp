#include "Intern.hpp"

int main(void) 
{
    std::cout << "------------------------------------------------" << std::endl;
    {
        Intern  intern;
        Form    *form;
        std::cout << YELLOW << "Trying to create a shrubbery creation form.." << NC << std::endl;
        form = intern.makeForm("shrubbery creation", "Perpignan");
        std::cout << *form << std::endl;
        delete (form);
    }
    std::cout << "------------------------------------------------" << std::endl;
    {
        Intern  intern;
        Form    *form;
        std::cout << YELLOW << "Trying to create a robotomy request form.." << NC << std::endl;
        form = intern.makeForm("robotomy request", "Theouche");
        std::cout << *form << std::endl;
        delete (form);
    }
    std::cout << "------------------------------------------------" << std::endl;
    {
        Intern  intern;
        Form    *form;
        std::cout << YELLOW << "Trying to create a presidential pardon form.." << NC << std::endl;
        form = intern.makeForm("presidential pardon", "Adriano");
        std::cout << *form << std::endl;
        delete (form);
    }
    std::cout << "------------------------------------------------" << std::endl;
    {
        try
        {
          Intern  intern;
          Form    *form;
          std::cout << YELLOW << "Trying to create a execute order 66 form.." << NC << std::endl;
          form = intern.makeForm("execute order 66", "Jedis");
          std::cout << *form << std::endl;
          delete (form);
        }
        catch(std::exception &e)
        {
          std::cerr << RED << "- EXCEPTION: " << e.what() << NC << std::endl;
        }
        
    }
    std::cout << "------------------------------------------------" << std::endl;
}