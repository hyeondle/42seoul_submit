/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:35:29 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/26 20:22:52 by hyeondle         ###   ########.fr       */
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
	size_t o_level = 0;
	for (int i = 0; i < 4; i++)
	{
		if (levelTable[i] == level)
			o_level = i + 1;
	}
	switch(o_level)
	{
		case 1:
			(this->*caller[0])();
		case 2:
			(this->*caller[1])();
		case 3:
			(this->*caller[2])();
		case 4:
		{
			(this->*caller[3])();
			break;
		}
		default:
		{
			std::cout << "nothing" << std::endl;
			break;
		}
	}
}