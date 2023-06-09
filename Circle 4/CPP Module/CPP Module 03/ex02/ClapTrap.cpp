/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:20:16 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/27 20:20:16 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <new>

// Basic Variable Controller
void			ClapTrap::setHitPoint(unsigned int amount)		{	this->hitPoint = amount;		}
void			ClapTrap::setEnergyPoint(unsigned int amount)	{	this->energyPoint =  amount;	}
void			ClapTrap::setAttackDamage(unsigned int amount)	{	this->attackDamage = amount;	}
void			ClapTrap::setName(std::string name)				{	this->name = name;				}
unsigned int	ClapTrap::getHitPoint(void)						{	return this->hitPoint;			}
unsigned int	ClapTrap::getEnergyPoint(void)					{	return this->energyPoint;		}
unsigned int	ClapTrap::getAttackDamage(void)					{	return this->attackDamage;		}
std::string		ClapTrap::getName(void)							{	return this->name;				}
// Constructors
ClapTrap::ClapTrap()
{
	this->name = "unnamed";
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;
	std::cout << "\e[0;33mDefault Constructor called\e[0m" << std::endl;
}
ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hitPoint = 10;
	this->energyPoint = 10;
	this->attackDamage = 0;
	std::cout << "\e[0;33mDefined Constructor called\e[0m" << " Name : " << this->name << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &copy)
{
	this->name = copy.name;
	this->hitPoint = copy.hitPoint;
	this->energyPoint = copy.energyPoint;
	this->attackDamage = copy.attackDamage;
	std::cout << "\e[0;33mCopy Constructor called\e[0m" << std::endl;
}
// Destructor
ClapTrap::~ClapTrap()
{
	std::cout << "\e[0;31mDestructor(ClapTrap) called\e[0m" << " Name : " << this->name << std::endl;
}
// Operators
ClapTrap & ClapTrap::operator=(const ClapTrap &assign)
{
	if (this != &assign)
	{
		this->name = assign.name;
		this->hitPoint = assign.hitPoint;
		this->energyPoint = assign.energyPoint;
		this->attackDamage = assign.attackDamage;
	}
	return *this;
}
//	Functions(Protected)
void	ClapTrap::dead(void)
{
	std::cout << getName() << " is already dead. Can't do anything" << std::endl;
}
void	ClapTrap::noEnergy(void)
{
	std::cout << getName() << " has no more energy." << std::endl;
}
//	Functions(Public)
void	ClapTrap::displayState(void)
{
	std::cout << getName() << "\'s statement" << std::endl;
	std::cout << "Hit Point 	:	" << getHitPoint() << std::endl;
	std::cout << "Energy Point	:	" << getEnergyPoint() << std::endl;
	std::cout << "Attack Damage	:	" << getAttackDamage() << std::endl;
}
int		ClapTrap::statecheck(void)
{
	if (getHitPoint() == 0)
	{
		dead();
		return 1;
	}
	if (getEnergyPoint() == 0)
	{
		noEnergy();
		return 2;
	}
	return 0;
}

void	ClapTrap::attack(const std::string& target)
{
	if (statecheck())
		return ;
	std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	setEnergyPoint(getEnergyPoint() - 1);
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (getHitPoint() == 0)
	{
		std::cout << getName() << " is already dead!" << std::endl;
		return ;
	}
	std::cout << getName() << " lose " << amount << " hit point!" << std::endl;
	if (getHitPoint() > amount)
		setHitPoint(getHitPoint() - amount);
	else
		setHitPoint(0);
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (statecheck())
		return ;
	std::cout << getName() << " restored " << amount << " hit point!" << std::endl;
	setHitPoint(getHitPoint() + amount);
	setEnergyPoint(getEnergyPoint() - 1);
}