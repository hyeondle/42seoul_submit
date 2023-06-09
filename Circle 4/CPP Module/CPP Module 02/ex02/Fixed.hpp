/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:51:49 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/26 22:51:50 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	public:
		// Constructors
		Fixed();
		Fixed(const int raw);
		Fixed(const float raw);
		Fixed(const Fixed &copy);
		// Destructor
		~Fixed();
		// Operators
		Fixed&	operator=(const Fixed &target);
		bool	operator>(const Fixed &target);
		bool	operator<(const Fixed &target);
		bool	operator>=(const Fixed &target);
		bool	operator<=(const Fixed &target);
		bool	operator==(const Fixed &target);
		bool	operator!=(const Fixed &target);
		Fixed	operator+(const Fixed &target);
		Fixed	operator-(const Fixed &target);
		Fixed	operator*(const Fixed &target);
		Fixed	operator/(const Fixed &target);
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);
	public:
		// Functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static const Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static const Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
	private:
		// Variables
		int	fixedPoint;
		static const int fractionalBits = 8;
};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif