/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:27:58 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/28 03:29:14 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors
Cat::Cat()
{
	this->type = "Cat";
	this->own = new Brain();
	std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}
Cat::Cat(const Cat &copy)
{
	this->own = new Brain(*copy.own);
    this->type = copy.type;
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
}
// Destructor
Cat::~Cat()
{
	delete this->own; // to make leak, delete this line
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}
// Operators
Cat & Cat::operator=(const Cat &assign)
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

void Cat::makeSound(void) const
{
	std::cout << "Nyaa..." << std::endl;
}

Brain* Cat::getBrain(void) const
{
	return (own);
}