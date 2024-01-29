/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:28:08 by hyeondle          #+#    #+#             */
/*   Updated: 2023/10/27 14:32:57 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}
Intern::~Intern() {}
Intern::Intern(const Intern& src) {	(void)src;	}
Intern& Intern::operator=(const Intern& rhs) {
    if (this != &rhs) {}
    return *this;
}

Intern::FormEntry Intern::formEntries[] = {
    {"shrubbery creation", &Intern::createShrubbery},
    {"robotomy request", &Intern::createRobotomy},
    {"presidential pardon", &Intern::createPresidential}
};


AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
	for (size_t i = 0; i < sizeof(formEntries) / sizeof(FormEntry); i++)
	{
		if (formName == formEntries[i].formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return formEntries[i].creatorFunc(target);
		}
	}
	std::cout << "Unknown form: " << formName << std::endl;
	return 0;
}

AForm* Intern::createShrubbery(const std::string& target) {	return new ShrubberyCreationForm(target);	}
AForm* Intern::createRobotomy(const std::string& target) {	return new RobotomyRequestForm(target);	}
AForm* Intern::createPresidential(const std::string& target) {	return new PresidentialPardonForm(target);	}