/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:27:38 by hyeondle          #+#    #+#             */
/*   Updated: 2023/10/27 14:51:58 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : name("None"), isSigned(false), signGrade(150), executeGrade(150){}
Form::~Form(){}
Form::Form(const Form &copy) : name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade), executeGrade(copy.executeGrade){}
Form & Form::operator=(const Form &assign)
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

Form::Form(std::string name, int signGrade, int executeGrade) : name(name), signGrade(signGrade), executeGrade(executeGrade)
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

std::string Form::getName() {return name;}
void Form::setName(std::string name) {*(std::string *)&this->name = name;}
bool Form::getIsSigned() {return isSigned;}
int Form::getSignGrade() {return signGrade;}
int Form::getExecuteGrade() {return executeGrade;}

void Form::beSigned(Bureaucrat admin)
{
	if (admin.getGrade() > signGrade)
		throw GradeTooLowException();
	isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is Too High";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is Too Low";
}

std::ostream &operator<<(std::ostream &os, Form &b)
{
    os << b.getName() << "\n-----\nIs signed? : " << b.getIsSigned() << "\nRequire sign grade is : " << b.getSignGrade() << "\nRequire execute grade is : " << b.getExecuteGrade() << "\n-----" << std::endl;
    return os;
}