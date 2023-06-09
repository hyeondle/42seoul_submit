/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:26:04 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/20 21:11:25 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
	name = "noname";
}

Zombie::~Zombie(void)
{
	std::cout << name << ": XXXX XX XX XXXX X XXX" << std::endl;
}

void Zombie::getname(std::string name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraaiiiiiiinnnzzzZ..." << std::endl;
}