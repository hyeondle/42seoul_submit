/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:50:16 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/26 20:15:25 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie a;

	a.announce();
	a.getname("al");
	a.announce();
	Zombie* ptr;
	ptr = zombieHorde(8, "ome");
	for (int i=0;i<8;i++)
	{
		ptr[i].announce();
	}
	delete [] ptr;
}