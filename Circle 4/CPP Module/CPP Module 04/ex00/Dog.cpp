/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:27:42 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/28 03:29:20 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors
Dog::Dog()
{
	this->type = "Dog";
	std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
}
Dog::Dog(const Dog &copy)
{
	this->type = copy.type;
	std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
}
// Destructor
Dog::~Dog()
{
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
}
// Operators
Dog & Dog::operator=(const Dog &assign)
{
	if (this != &assign)
		this->type = assign.type;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Bark Bark!" << std::endl;
}