/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:28:28 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/28 03:29:03 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
# include <iostream>
# include <string>

class Dog : public Animal
{
	public:
		// Constructors
		Dog();
		Dog(const Dog &copy);
		// Destructor
		~Dog();
		// Operators
		Dog & operator=(const Dog &assign);
	public:
		void	makeSound() const;
		Brain*	getBrain() const;
	private:
		Brain *own;
};

#endif