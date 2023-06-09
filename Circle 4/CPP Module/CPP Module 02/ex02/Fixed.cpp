/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:51:26 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/26 22:51:45 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

// Constructors
Fixed::Fixed()
{
	fixedPoint = 0;
}

Fixed::Fixed(const int raw)
{
	fixedPoint = raw << fractionalBits;
}

Fixed::Fixed(const float raw)
{
	fixedPoint = static_cast<int>(roundf(raw * (1 << fractionalBits)));
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

// Destructor
Fixed::~Fixed()
{
}

// Operators
Fixed & Fixed::operator=(const Fixed &target)
{
	if (this != &target)
		fixedPoint = target.fixedPoint;
	return *this;
}

bool Fixed::operator>(const Fixed &target)
{
	return this->fixedPoint > target.fixedPoint;
}

bool Fixed::operator<(const Fixed &target)
{
	return this->fixedPoint < target.fixedPoint;
}

bool Fixed::operator>=(const Fixed &target)
{
	return this->fixedPoint >= target.fixedPoint;
}

bool Fixed::operator<=(const Fixed &target)
{
	return this->fixedPoint <= target.fixedPoint;
}

bool Fixed::operator==(const Fixed &target)
{
	return this->fixedPoint == target.fixedPoint;
}

bool Fixed::operator!=(const Fixed &target)
{
	return this->fixedPoint != target.fixedPoint;
}

Fixed Fixed::operator+(const Fixed &target)
{
	return Fixed(toFloat() + target.toFloat());
}

Fixed Fixed::operator-(const Fixed &target)
{
	return Fixed(toFloat() - target.toFloat());
}

Fixed Fixed::operator*(const Fixed &target)
{
	return Fixed(toFloat() * target.toFloat());
}

Fixed Fixed::operator/(const Fixed &target)
{
	return Fixed(toFloat() / target.toFloat());
}

Fixed& Fixed::operator++() {
    fixedPoint += 1;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

Fixed& Fixed::operator--() {
    fixedPoint += 1;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    ++(*this);
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
	return os;
}

// Functions

int Fixed::getRawBits(void) const
{
	return fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPoint = raw;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(fixedPoint) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return fixedPoint >> fractionalBits;
}

const Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return b;
	else
		return a;
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return b;
	else
		return a;
}

const Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	else
		return b;
}
