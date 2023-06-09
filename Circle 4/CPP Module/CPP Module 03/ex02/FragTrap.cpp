/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:20:11 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/27 20:20:11 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

// Constructors
FragTrap::FragTrap()
{
	this->name			= "unnamed_Scav";
	this->hitPoint		= 100;
	this->energyPoint	= 100;
	this->attackDamage	= 30;
	std::cout << "\e[0;33mDefault Constructor called of FragTrap\e[0m" << std::endl;
}
FragTrap::FragTrap(std::string name)
{
	this->name			= name;
	this->hitPoint		= 100;
	this->energyPoint	= 100;
	this->attackDamage	= 30;
	std::cout << "\e[0;33mDefined Constructor called of FragTrap\e[0m" << " Name : " << this->name << std::endl;
}
FragTrap::FragTrap(const FragTrap &copy)
{
	this->name			= copy.name;
	this->hitPoint		= copy.hitPoint;
	this->energyPoint	= copy.energyPoint;
	this->attackDamage	= copy.attackDamage;
	std::cout << "\e[0;33mCopy Constructor called of FragTrap\e[0m" << std::endl;
}
// Destructor
FragTrap::~FragTrap()
{
	std::cout << "\e[0;31mDestructor called of FragTrap\e[0m" << " Name : " << this->name << std::endl;
}
// Operators
FragTrap & FragTrap::operator=(const FragTrap &assign)
{
	if (this != &assign)
	{
		this->name			= assign.name;
		this->hitPoint		= assign.hitPoint;
		this->energyPoint	= assign.energyPoint;
		this->attackDamage	= assign.attackDamage;
	}
	return *this;
}
// Functions
void FragTrap::highFivesGuys()
{
	if (statecheck())
		return ;
	std::cout << getName() << " : (Clap!) high five~!" << std::endl;
	setEnergyPoint(getEnergyPoint() - 1);
}