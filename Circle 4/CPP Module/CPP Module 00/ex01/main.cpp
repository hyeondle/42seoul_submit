/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:28:32 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/26 17:02:05 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main()
{
	PhoneBook	dic;
	std::string	order;

	std::cout << "My Little Phone Book\n";
	while (1)
	{
		std::cout << "Order : ";
		getline(std::cin, order);
		if (std::cin.eof())
			break;
		if (order.compare("ADD") == 0)
			dic.padd();
		else if (order.compare("SEARCH") == 0)
		{
			dic.psearch();
			std::cin.clear();
			std::cin.ignore();
		}
		else if (order.compare("EXIT") == 0)
			break;
	}
}