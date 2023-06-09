/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:28:33 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/28 03:29:00 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

// Constructors
WrongCat::WrongCat()
{
	this->type = "Wrong Cat";
	std::cout << "\e[0;33mDefault Constructor called of WrongCat\e[0m" << std::endl;
}
WrongCat::WrongCat(const WrongCat &copy)
{
	this->type = copy.type;
	std::cout << "\e[0;33mCopy Constructor called of WrongCat\e[0m" << std::endl;
}
// Destructor
WrongCat::~WrongCat()
{
	std::cout << "\e[0;31mDestructor called of WrongCat\e[0m" << std::endl;
}
// Operators
WrongCat & WrongCat::operator=(const WrongCat &assign)
{
	if (this != &assign)
		this->type = assign.type;
	return *this;
}
