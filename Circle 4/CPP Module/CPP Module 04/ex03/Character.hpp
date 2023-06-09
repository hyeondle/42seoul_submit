/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:28:41 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/28 03:28:58 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"
# include <iostream>
# include <string>

class Character : public ICharacter
{
	public:
		Character();
		Character(std::string const & name);
		Character(const Character &copy);
		~Character();
		Character & operator=(const Character &assign);
		std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
	private:
		std::string name;
		AMateria* inventory[4];
};

#endif