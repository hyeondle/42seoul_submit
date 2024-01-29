/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:28:12 by hyeondle          #+#    #+#             */
/*   Updated: 2023/10/26 17:28:20 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : target("None") {}
RobotomyRequestForm::~RobotomyRequestForm() {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), target(src.target) {}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
    if (this != &rhs) {
        AForm::operator=(rhs);
        *(std::string *)&this->target = rhs.target;
    }
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    if (!getIsSigned()) throw GradeTooLowException();
    if (executor.getGrade() > getExecuteGrade()) throw GradeTooLowException();
    std::cout << "Drilling noises..." << std::endl;
    if (rand() % 2)
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy of " << target << " failed." << std::endl;
}