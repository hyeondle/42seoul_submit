/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:20:26 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/27 20:20:27 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

// Basic Variable Controller
unsigned int	ScavTrap::getMode(void)					{	return this->mode;	}
void			ScavTrap::setMode(unsigned int mode)	{	this->mode = mode;	}
// Constructors
ScavTrap::ScavTrap()
{
	this->name			= "unnamed_Scav";
	this->hitPoint		= 100;
	this->energyPoint	= 50;
	this->attackDamage	= 20;
	this->mode			= 0;
	std::cout << "\e[0;33mDefault Constructor called of ScavTrap\e[0m" << std::endl;
}
ScavTrap::ScavTrap(std::string name)
{
	this->name			= name;
	this->hitPoint		= 100;
	this->energyPoint	= 50;
	this->attackDamage	= 20;
	this->mode			= 0;
	std::cout << "\e[0;33mDefined Constructor called of ScavTrap\e[0m" << " Name : " << this->name << std::endl;
}
ScavTrap::ScavTrap(const ScavTrap &copy)
{
	this->name			= copy.name;
	this->hitPoint		= copy.hitPoint;
	this->energyPoint	= copy.energyPoint;
	this->attackDamage	= copy.attackDamage;
	this->mode			= copy.mode;
	std::cout << "\e[0;33mCopy Constructor called of ScavTrap\e[0m" << std::endl;
}
// Destructor
ScavTrap::~ScavTrap()
{
	std::cout << "\e[0;31mDestructor called of ScavTrap\e[0m" << " Name : " << this->name << std::endl;
}
// Operators
ScavTrap & ScavTrap::operator=(const ScavTrap &assign)
{
	if (this != &assign)
	{
		this->name			= assign.name;
		this->hitPoint		= assign.hitPoint;
		this->energyPoint	= assign.energyPoint;
		this->attackDamage	= assign.attackDamage;
		this->mode			= assign.mode;
	}
	return *this;
}
// Functions
void	ScavTrap::attack(const std::string &target)
{
	if (statecheck())
		return ;
	std::cout << "ScavTrap " << getName() << " shots " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	setEnergyPoint(getEnergyPoint() - 1);
}
void	ScavTrap::guardGate(void)
{
	if (this->mode == 1)
		std::cout << getName() << "is already in Gate keeper mode." << std::endl;
	else
	{
		std::cout << getName() << "is now in Gate keeper mode." << std::endl;
		this->mode = 1;
		setEnergyPoint(getEnergyPoint() - 1);
	}
}