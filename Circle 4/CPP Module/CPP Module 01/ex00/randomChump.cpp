/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:27:32 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/26 20:08:40 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>
#include <ctime>

void randomChump(std::string name)
{
	int			length;

	std::string	new_name;

	length = rand() % 10 + 1;
	new_name = name;
	new_name = new_name + '_';
	new_name = new_name + (char)(rand() % 26 + 65);
	for (int i = 1; i < length; i++)
		new_name = new_name + (char)(rand() % 26 + 97);
	Zombie deadman(new_name);
	deadman.announce();
}