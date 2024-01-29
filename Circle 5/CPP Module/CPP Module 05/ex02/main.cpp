/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:27:52 by hyeondle          #+#    #+#             */
/*   Updated: 2023/10/27 14:22:46 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    srand(static_cast<unsigned int>(time(0)));

    Bureaucrat bob("Bob", 10);
    Bureaucrat jin("jin", 5);
    Bureaucrat kyle("kyle", 140);
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Marvin");
    PresidentialPardonForm pardon("Prisoner");

    bob.signForm(shrub);
    bob.signForm(robot);
    bob.signForm(pardon);

    bob.executeForm(shrub);
    bob.executeForm(robot);
    bob.executeForm(pardon);

    std::cout << std::endl;

    jin.signForm(shrub);
    jin.signForm(robot);
    jin.signForm(pardon);

    jin.executeForm(shrub);
    jin.executeForm(robot);
    jin.executeForm(pardon);

    std::cout << std::endl;

    kyle.signForm(shrub);
    kyle.signForm(robot);
    kyle.signForm(pardon);

    kyle.executeForm(shrub);
    kyle.executeForm(robot);
    kyle.executeForm(pardon);
    return 0;
}