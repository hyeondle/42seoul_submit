/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:26:43 by hyeondle          #+#    #+#             */
/*   Updated: 2023/10/27 13:39:35 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("None"), grade(150){}
Bureaucrat::Bureaucrat(std::string name, int grade):name(name), grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}
Bureaucrat::~Bureaucrat(){}
Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade){}
Bureaucrat & Bureaucrat::operator=(const Bureaucrat &assign)
{
	if (this != &assign)
	{
		*(std::string *)&this->name = assign.name;
		this->grade = assign.grade;
	}
	return *this;
}

std::string	Bureaucrat::getName()					{	return name;	}
void		Bureaucrat::setName(std::string name)	{	*(std::string *)&this->name = name;	}
int			Bureaucrat::getGrade()					{	return grade;	}
void		Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->grade = grade;
}

void		Bureaucrat::increament()
{
	if (this->grade <= 1)
		throw GradeTooHighException();
	this->grade--;
}

void		Bureaucrat::decreament()
{
	if (this->grade >= 150)
		throw GradeTooLowException();
	this->grade++;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is Too High";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is Too Low";
}

std::ostream &operator<<(std::ostream &os, Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return os;
}