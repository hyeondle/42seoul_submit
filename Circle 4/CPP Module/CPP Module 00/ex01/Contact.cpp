/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 16:28:45 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/26 17:02:05 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	for (int i = 0; i < 5; i++)
		contact[i] = "";
	infos[0] = "First Name     : ";
	infos[1] = "Last Name      : ";
	infos[2] = "NickName       : ";
	infos[3] = "Phone Number   : ";
	infos[4] = "DARKEST SECRET : ";
}

Contact::~Contact()
{
}

void Contact::wronginput(int n)
{
	if (std::cin.eof())
			exit(1);
	while (contact[n].empty() || isprintable(contact[n]))
	{
		std::cout << "WARNING : YOU SHOULD PUT VALID INPUT\nInput : ";
		getline(std::cin, contact[n]);
	}
}

bool Contact::isprintable(std::string input)
{
	for (unsigned long i = 0; i < input.size(); ++i)
	{
		if (std::isprint(input.at(i)) == false)
			return true;
	}
	return false;
}

void Contact::cadd(int i)
{
	std::cout << "PhoneBook index " << i << "'s information\n";
	std::cout << infos[0];
	getline(std::cin, contact[0]);
	if(contact[0].empty() || isprintable(contact[0]))
		wronginput(0);
	std::cout << infos[1];
	getline(std::cin, contact[1]);
	if(contact[1].empty() || isprintable(contact[1]))
		wronginput(1);
	std::cout << infos[2];
	getline(std::cin, contact[2]);
	if(contact[2].empty() || isprintable(contact[2]))
		wronginput(2);
	std::cout << infos[3];
	getline(std::cin, contact[3]);
	if(contact[3].empty() || isprintable(contact[3]))
		wronginput(3);
	std::cout << infos[4];
	getline(std::cin, contact[4]);
	if(contact[4].empty() || isprintable(contact[4]))
		wronginput(4);
}

void Contact::csearch(int n)
{
	std::cout.width(10);
	std::cout << n << '|';
	for (int i = 0; i < 3; i++)
	{
		std::string temp = contact[i];
		if (temp.length() > 10)
			temp = temp.substr(0, 9) + ".";
		std::cout.width(10);
		std::cout << temp;
		if (i != 2)
			std::cout << '|';
	}
	std::cout << "\n";
}

void Contact::show()
{
	for (int i = 0; i < 5; i++)
		std::cout << infos[i] << contact[i] << "\n";
	std::cout << "\n";
}
