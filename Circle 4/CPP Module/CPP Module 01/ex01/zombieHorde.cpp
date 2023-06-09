/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 20:26:52 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/26 20:14:56 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <string>

Zombie*	zombieHorde(int N, std::string name)
{
	if (N <= 0)
		return nullptr;

	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].getname(name + std::to_string(i + 1));
	return horde;
}