/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:29:44 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/26 17:02:06 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	head = 0;
	fulled = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::padd()
{
	contact[head].cadd(head + 1);
	head++;
	if (head == 8)
		fulled = 1;
	head = head % 8;
}

void PhoneBook::psearch()
{
	int index;

	while(1)
	{
		for (int i = 0; i < 8; i++)
			contact[i].csearch(i + 1);
		std::cout << "Index (0 to show all, 9 to return previous menu) : ";
		if (!(std::cin >> index))
		{
			std::cout << "Invalid Input\n";
			std::cin.clear();
			std::cin.ignore();
			return;
		}
		if (index == 9)
			break;
		if (index < 9 && index > 0)
		{
			if (fulled != 1 && index > head)
				std::cout << "Out of Range\n";
			else
				contact[index - 1].show();
		}
		else if (index == 0)
		{
			if (fulled != 1)
				for (int i = 0; i < head; i++)
					contact[i].show();
			else
				for (int i = 0; i < 8; i++)
					contact[i].show();
		}
		else
			std::cout << "Wrong Input\n";
	}
}
