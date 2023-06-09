/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:20:28 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/27 20:20:29 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

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

	a.setName("alpha");
	c.setName("gamma");

	// a.displayState();
	// b.displayState();
	// c.displayState();
	// d.displayState();

	// a.setAttackDamage(3);
	// b.setAttackDamage(5);
	// attack(c, d);
	// d.displayState();
	// c.beRepaired(500);
	// c.displayState();
	// attack(a, b);
	// b.displayState();
	// attack(a, c);
	// c.displayState();
	// attack(c, a);
	// a.displayState();
	// attack(d, c);
	// c.displayState();
	// for (int i = 0; i < 51; i++)
	// 	attack(d, c);
	// c.displayState();
	// d.displayState();
}