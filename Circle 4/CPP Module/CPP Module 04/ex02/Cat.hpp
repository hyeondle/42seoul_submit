/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:28:24 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/28 03:29:04 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
# include <iostream>
# include <string>
# include "Brain.hpp"
class Cat : public Animal
{
	public:
		// Constructors
		Cat();
		Cat(const Cat &copy);
		// Destructor
		~Cat();
		// Operators
		Cat & operator=(const Cat &assign);
	public:
		void makeSound() const;
		Brain*	getBrain() const;
	private:
		Brain *own;
};

#endif