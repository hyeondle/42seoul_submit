/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:28:10 by hyeondle          #+#    #+#             */
/*   Updated: 2023/10/27 14:40:40 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main() {
    Intern intern;
    Bureaucrat john("John", 1);
    Bureaucrat timmy("Tim", 150);

    AForm* shrubberyForm = intern.makeForm("shrubbery creation", "Home");
    if (shrubberyForm) {
        std::cout << shrubberyForm->getName() << std::endl;
        john.signForm(*shrubberyForm);
        john.executeForm(*shrubberyForm);
        std::cout << std::endl;
        timmy.signForm(*shrubberyForm);
        timmy.executeForm(*shrubberyForm);
    }
    std::cout << std::endl;
    AForm* robotomyForm = intern.makeForm("robotomy request", "Marvin");
    if (robotomyForm) {
        std::cout << robotomyForm->getName() << std::endl;
        john.signForm(*robotomyForm);
        john.executeForm(*robotomyForm);
        std::cout << std::endl;
        timmy.signForm(*robotomyForm);
        timmy.executeForm(*robotomyForm);
    }
    std::cout << std::endl;
    AForm* pardonForm = intern.makeForm("presidential pardon", "Prisoner");
    if (pardonForm) {
        std::cout << pardonForm->getName() << std::endl;
        john.signForm(*pardonForm);
        john.executeForm(*pardonForm);
        std::cout << std::endl;
        timmy.signForm(*robotomyForm);
        timmy.executeForm(*robotomyForm);
    }
    std::cout << std::endl;
    AForm* wrongForm = intern.makeForm("unknown form", "Nowhere");
    if (wrongForm) {
        std::cout << "if this printed, test would be failed" << std::endl;
    }

    return 0;
}
