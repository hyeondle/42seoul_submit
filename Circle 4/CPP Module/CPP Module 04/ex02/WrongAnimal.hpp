/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:28:32 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/28 03:29:01 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{
	public:
		// Constructors
		WrongAnimal();
		WrongAnimal(const WrongAnimal &copy);
		// Destructor
		virtual ~WrongAnimal();
		// Operators
		WrongAnimal & operator=(const WrongAnimal &assign);
	public:
		virtual void makeSound(void) const;
		std::string getType(void) const;
	protected:
		std::string type;
};

#endif