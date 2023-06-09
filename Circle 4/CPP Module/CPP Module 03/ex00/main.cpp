/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:20:35 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/27 20:20:35 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

void attack(ClapTrap &a, ClapTrap &b)
{
	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
}

int main(void)
{
	ClapTrap a("SLIME");
	ClapTrap b("GOBLIN");

	a.displayState();
	b.displayState();

	attack(a, b);
	a.displayState();
	b.displayState();

	a.setAttackDamage(3);
	attack(a, b);
	a.displayState();
	b.displayState();

	attack(a, b);
	attack(a, b);
	attack(a, b);
	attack(a, b);
	attack(a, b);
	a.displayState();
	b.displayState();
	b.beRepaired(10);
}