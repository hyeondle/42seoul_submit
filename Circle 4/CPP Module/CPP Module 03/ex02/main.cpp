/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:20:07 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/27 20:20:08 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

template<class T, class L>
void attack(T &a, L &b)
{
	a.attack(b.getName());
	b.takeDamage(a.getAttackDamage());
}

int main(void)
{
	ClapTrap a;
	ClapTrap b("beta");
	ScavTrap c;
	ScavTrap d("delta");
	FragTrap e;
	FragTrap f("zeta");

	a.setName("alpha");
	c.setName("gamma");
	e.setName("epsilon");
	a.displayState();
	c.displayState();
	e.displayState();

	attack(a, c);
	attack(c, e);
	attack(e, a);
	a.displayState();
	c.displayState();
	e.displayState();

	e.highFivesGuys();
	f.highFivesGuys();

	attack(a, c);
	attack(c, e);
	attack(e, a);
	a.displayState();
	c.displayState();
	e.displayState();
}