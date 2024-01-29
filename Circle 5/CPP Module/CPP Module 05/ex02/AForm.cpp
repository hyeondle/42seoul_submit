/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:27:47 by hyeondle          #+#    #+#             */
/*   Updated: 2023/10/27 13:54:41 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : name("None"), isSigned(false), signGrade(150), executeGrade(150){}
AForm::~AForm(){}
AForm::AForm(const AForm &copy) : name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade), executeGrade(copy.executeGrade) {}
AForm & AForm::operator=(const AForm &assign)
{
	if (this != &assign)
	{
		*(std::string *)&this->name = assign.name;
		this->isSigned = assign.isSigned;
		*(int *)&this->signGrade = assign.signGrade;
		*(int *)&this->executeGrade = assign.executeGrade;
	}
	return *this;
}

AForm::AForm(std::string name, int signGrade, int executeGrade) : name(name), signGrade(signGrade), executeGrade(executeGrade)
{
	if (signGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150)
		throw GradeTooLowException();
	if (executeGrade < 1)
		throw GradeTooHighException();
	else if (executeGrade > 150)
		throw GradeTooLowException();
}

std::string AForm::getName() const {return name;}
void AForm::setName(std::string name) {*(std::string *)&this->name = name;}
bool AForm::getIsSigned() const {return isSigned;}
int AForm::getSignGrade() {return signGrade;}
int AForm::getExecuteGrade() const {return executeGrade;}

void AForm::beSigned(Bureaucrat admin)
{
	if (admin.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is Too High";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is Too Low";
}

std::ostream &operator<<(std::ostream &os, AForm &b)
{
    os << b.getName() << "\n-----\nIs signed? : " << b.getIsSigned() << "\nRequire sign grade is : " << b.getSignGrade() << "\nRequire execute grade is : " << b.getExecuteGrade() << "\n-----" << std::endl;
    return os;
}