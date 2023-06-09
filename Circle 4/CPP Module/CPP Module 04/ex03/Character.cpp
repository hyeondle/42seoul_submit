/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:28:40 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/28 03:28:58 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
}
Character::Character(std::string const & name)
{
	this->name = name;
	for (int i = 0; i < 4; ++i)
		inventory[i] = nullptr;
}
Character::Character(const Character &copy)
{
	for (int i = 0; i < 4; ++i)
	{
        if (copy.inventory[i])
            this->inventory[i] = copy.inventory[i]->clone();
        else
            this->inventory[i] = nullptr;
	}
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
	{
        if (this->inventory[i])
            delete this->inventory[i];
    }
}

Character & Character::operator=(const Character &assign)
{
	if (this != &assign)
	{
        this->name = assign.name;
        for (int i = 0; i < 4; ++i)
		{
            if (this->inventory[i])
                delete this->inventory[i];
            if (assign.inventory[i])
                this->inventory[i] = assign.inventory[i]->clone();
            else
                this->inventory[i] = nullptr;
        }
    }
    return *this;
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
	{
        if (inventory[i] == nullptr)
		{
            inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx > 3 || inventory[idx] == nullptr)
        return;
    inventory[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx > 3 || inventory[idx] == nullptr)
        return;
    inventory[idx]->use(target);
}

std::string const & Character::getName() const
{
	return this->name;
}