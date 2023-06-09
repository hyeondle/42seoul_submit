/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:52:35 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/26 20:09:40 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

int main(void)
{
	Zombie first("first");
	Zombie second("second");

	first.announce();
	second.announce();
	Zombie *ptr;

	ptr = newZombie("alpha");
	ptr->announce();
	delete ptr;

	srand(time(NULL));
	randomChump("Omega");
	randomChump("Omega");
}