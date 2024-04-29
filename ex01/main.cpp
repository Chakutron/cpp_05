#include "Form.hpp"

int main(void) 
{
    std::cout << "------------------------------------------------" << std::endl;
	{
        Bureaucrat chaku("Chaku", 42);
        std::cout << chaku << std::endl;
        Form secretForm("Order #66", 66, 66);
        std::cout << secretForm << std::endl;
        std::cout << YELLOW << "Trying to sign the form.." << NC << std::endl;
        chaku.signForm(secretForm);
        std::cout << secretForm << std::endl;
    }
    std::cout << "------------------------------------------------" << std::endl;
	{
        Bureaucrat theouche("Theouche", 1);
        std::cout << theouche << std::endl;
        Form secretForm("Order #66", 66, 66);
        std::cout << secretForm << std::endl;
        std::cout << YELLOW << "Trying to sign the form.." << NC << std::endl;
        theouche.signForm(secretForm);
        std::cout << secretForm << std::endl;
    }
    std::cout << "------------------------------------------------" << std::endl;
	{
        Bureaucrat adriano("Adriano", 150);
        std::cout << adriano << std::endl;
        Form secretForm("Order #66", 66, 66);
        std::cout << secretForm << std::endl;
        std::cout << YELLOW << "Trying to sign the form.." << NC << std::endl;
        adriano.signForm(secretForm);
        std::cout << secretForm << std::endl;
    }
}