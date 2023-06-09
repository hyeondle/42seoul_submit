/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:27:39 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/28 03:29:21 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

// Constructors
Cat::Cat()
{
	this->type = "Cat";
	std::cout << "\e[0;33mDefault Constructor called of Cat\e[0m" << std::endl;
}
Cat::Cat(const Cat &copy)
{
	this->type = copy.type;
	std::cout << "\e[0;33mCopy Constructor called of Cat\e[0m" << std::endl;
}
// Destructor
Cat::~Cat()
{
	std::cout << "\e[0;31mDestructor called of Cat\e[0m" << std::endl;
}
// Operators
Cat & Cat::operator=(const Cat &assign)
{
	if (this != &assign)
		this->type = assign.type;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Nyaa..." << std::endl;
}

