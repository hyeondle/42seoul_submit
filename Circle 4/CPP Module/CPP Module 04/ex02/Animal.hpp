/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:28:15 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/28 03:29:06 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{
	public:
		// Constructors
		Animal();
		Animal(const Animal &copy);
		// Destructor
		virtual ~Animal();
		// Operators
		Animal & operator=(const Animal &assign);
	public:
		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
	protected:
		std::string type;
};

#endif