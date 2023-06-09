/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:27:53 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/28 03:29:16 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

// Constructors
Animal::Animal()
{
	this->type = "Undefined Creature";
	std::cout << "\e[0;33mDefault Constructor called of Animal\e[0m" << std::endl;
}
Animal::Animal(const Animal &copy)
{
	this->type = copy.type;
	std::cout << "\e[0;33mCopy Constructor called of Animal\e[0m" << std::endl;
}
// Destructor
Animal::~Animal()
{
	std::cout << "\e[0;31mDestructor called of Animal\e[0m" << std::endl;
}
// Operators
Animal & Animal::operator=(const Animal &assign)
{
	if (this != &assign)
		this->type = assign.type;
	return *this;
}
// Functions
std::string Animal::getType(void) const
{
	return this->type;
}
void Animal::makeSound(void) const
{
	std::cout << "Undefined Creature is howling" << std::endl;
}