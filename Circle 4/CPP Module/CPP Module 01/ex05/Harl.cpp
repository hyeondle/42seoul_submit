/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:40:36 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/24 16:28:54 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void Harl::debug(void)
{
	std::cout << "debug" << std::endl;
}

void Harl::info(void)
{
	std::cout << "info" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "warning" << std::endl;
}

void Harl::error(void)
{
	std::cout << "error" << std::endl;
}

void Harl::complain(std::string level)
{
	std::string levelTable[4];
	{
		levelTable[0] = "DEBUG";
		levelTable[1] = "INFO";
		levelTable[2] = "WARNING";
		levelTable[3] = "ERROR";
	}
	void (Harl::*caller[4])(void);
	{
		caller[0] = &Harl::debug;
		caller[1] = &Harl::info;
		caller[2] = &Harl::warning;
		caller[3] = &Harl::error;
	}
	for (int i = 0; i < 4; i++)
	{
		if (levelTable[i] == level)
		{
			(this->*caller[i])();
			return ;
		}
	}
	std::cout << "nothing" << std::endl;
}