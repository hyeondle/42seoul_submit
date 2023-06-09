/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:17:25 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/20 18:52:28 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << name << ": XXXX XX XX XXXX X XXX" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraaiiiiiiinnnzzzZ..." << std::endl;
}