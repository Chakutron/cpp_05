#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("Unknown")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &other) : Form(other), _target(other.getTarget())
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
    (void)other;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget() const
{
    return (_target);
}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (this->getSigned() == false)
        throw Form::NotSignedException();
    else if (executor.getGrade() > this->getExecuteGrade())
        throw Form::GradeTooLowException();
    std::ofstream of((this->_target + "_shrubbery").c_str());
    of << "      ######        ######        ######      " << std::endl;
    of << "     ########      ########      ########     " << std::endl;
    of << "      ######        ######        ######      " << std::endl;
    of << "       ####          ####          ####       " << std::endl;
    of << "        ||            ||            ||        " << std::endl;
    of << "        ||            ||            ||        " << std::endl;
    of << "........||............||............||........" << std::endl;
    of << ".............................................." << std::endl;
    of.close();
    std::cout << LBLUE << " - File: " << BLUE << (this->_target + "_shrubbery").c_str() << LBLUE << " created and filled with ascii trees" << NC << std::endl;
}