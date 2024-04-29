#include "Bureaucrat.hpp"

int main(void) 
{
	try 
	{
        Bureaucrat chaku("Chaku", 42);
        std::cout << chaku << std::endl;
    }
    catch (std::exception &e) 
	{
        std::cerr << RED << "- EXCEPTION: " << e.what() << NC << std::endl;
    }
    std::cout << "------------------------------------------------" << std::endl;
    try 
	{
        Bureaucrat theouche("Theouche", 1);
        std::cout << theouche << std::endl;
        std::cout << YELLOW << "Trying to increment his grade.." << NC << std::endl;
        theouche.incrementGrade();
        std::cout << theouche << std::endl;
    }
    catch (std::exception &e) 
	{
        std::cerr << RED << "- EXCEPTION: " << e.what() << NC << std::endl;
    }
    std::cout << "------------------------------------------------" << std::endl;
    try 
	{
        Bureaucrat adriano("Adriano", 150);
        std::cout << adriano << std::endl;
        std::cout << YELLOW << "Trying to decrement his grade.." << NC << std::endl;
        adriano.decrementGrade();
        std::cout << adriano << std::endl;
    }
    catch (std::exception &e) 
	{
        std::cerr << RED << "- EXCEPTION: " << e.what() << NC << std::endl;
    }
}