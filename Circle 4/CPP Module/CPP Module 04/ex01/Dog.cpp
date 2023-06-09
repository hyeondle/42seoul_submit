/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:28:02 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/28 03:29:13 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

// Constructors
Dog::Dog()
{
	this->type = "Dog";
	this->own = new Brain();
	std::cout << "\e[0;33mDefault Constructor called of Dog\e[0m" << std::endl;
}
Dog::Dog(const Dog &copy)
{
    this->own = new Brain(*copy.own);
    this->type = copy.type;
    std::cout << "\e[0;33mCopy Constructor called of Dog\e[0m" << std::endl;
}
// Destructor
Dog::~Dog()
{
	delete this->own; // to make leak, delete this line
	std::cout << "\e[0;31mDestructor called of Dog\e[0m" << std::endl;
}
// Operators
Dog & Dog::operator=(const Dog &assign)
{
	if (this != &assign)
    {
        delete this->own;
        this->own = new Brain(*assign.own);
        this->type = assign.type;
    }
    std::cout << "\e[0;33mOperator= called of Dog\e[0m" << std::endl;
    return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Bark Bark!" << std::endl;
}

Brain* Dog::getBrain(void) const
{
	return (own);
}