/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:52:01 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/26 22:52:08 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Constructors
Fixed::Fixed()
{
	std::cout << "\e[0;33mDefault Constructor called\e[0m" << std::endl;
	fixedPoint = 0;
}

Fixed::Fixed(const int raw)
{
	std::cout << "\e[0;33mInt Constructor called\e[0m" << std::endl;
	fixedPoint = raw << fractionalBits;
}

Fixed::Fixed(const float raw)
{
	std::cout << "\e[0;33mFloat Constructor called\e[0m" << std::endl;
	fixedPoint = static_cast<int>(roundf(raw * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "\e[0;33mCopy Constructor called\e[0m" << std::endl;
	*this = copy;
}

// Destructor
Fixed::~Fixed()
{
	std::cout << "\e[0;31mDestructor called\e[0m" << std::endl;
}

// Operators
Fixed & Fixed::operator=(const Fixed &assign)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &assign)
		fixedPoint = assign.fixedPoint;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
	return os;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(fixedPoint) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return roundf(toFloat());
}