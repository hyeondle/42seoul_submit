/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:27:57 by hyeondle          #+#    #+#             */
/*   Updated: 2023/10/27 14:14:13 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : target("None") {}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), target(src.target) {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
        *(std::string *)&this->target = rhs.target;
    }
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw GradeTooLowException();
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	std::ofstream ofs(target + "_shrubbery");
	ofs << \
	"                                                         ." << std::endl <<
	"                                              .         ;" << std::endl <<
	"                 .              .              ;%     ;;" << std::endl <<
	"                   ,           ,                :;%  %;" << std::endl <<
	"                    :         ;                   :;%;'     .," << std::endl <<
	"           ,.        %;     %;            ;        %;'    ,;" << std::endl <<
	"             ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl <<
	"              %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl <<
	"               ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl <<
	"                `%;.     ;%;     %;'         `;%%;.%;'" << std::endl <<
	"                 `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl <<
	"                    `:%;.  :;bd%;          %;@%;'" << std::endl <<
	"                      `@%:.  :;%.         ;@@%;'" << std::endl <<
	"                        `@%.  `;@%.      ;@@%;" << std::endl <<
	"                          `@%%. `@%%    ;@@%;" << std::endl <<
	"                            ;@%. :@%%  %@@%;" << std::endl <<
	"                              %@bd%%%bd%%:;" << std::endl <<
	"                                #@%%%%%:;;" << std::endl <<
	"                                %@@%%%::;" << std::endl <<
	"                                %@@@%(o);  . '" << std::endl <<
	"                                %@@@o%;:(.,'" << std::endl <<
	"                            `.. %@@@o%::;" << std::endl <<
	"                               `)@@@o%::;" << std::endl <<
	"                                %@@(o)::;" << std::endl <<
	"                               .%@@@@%::;" << std::endl <<
	"                               ;%@@@@%::;." << std::endl <<
	"                              ;%@@@@%%:;;;." << std::endl <<
	"                          ...;%@@@@@%%:;;;;,.." << std::endl;
	ofs.close();
}
