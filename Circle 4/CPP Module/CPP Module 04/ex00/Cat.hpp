/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:27:41 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/28 03:29:20 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
# include <iostream>
# include <string>

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
	private:
};

#endif