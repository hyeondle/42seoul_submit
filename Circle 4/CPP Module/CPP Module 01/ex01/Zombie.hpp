/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:07:08 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/20 21:05:52 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
	private	:
		std::string name;
	public	:
		Zombie();
		~Zombie();
		void announce(void);
		void getname(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

#endif