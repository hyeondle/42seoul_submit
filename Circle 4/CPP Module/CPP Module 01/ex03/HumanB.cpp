/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 23:52:45 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/23 00:14:44 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = nullptr;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack()
{
	if (weapon == nullptr)
		std::cout << name << " attacks with their " << "fist" << std::endl;
	else
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}