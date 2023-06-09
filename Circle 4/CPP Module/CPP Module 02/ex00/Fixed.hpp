/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:52:23 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/26 22:52:23 by hyeondle         ###   ########.fr       */
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
		Fixed(const Fixed &copy);
		// Destructor
		~Fixed();
		// Operators
		Fixed & operator=(const Fixed &assign);
	public:
		int getRawBits(void) const;
		void setRawBits(int const raw);
	private:
		int	fixedPoint;
		static const int fractionalBits = 8;
};

#endif