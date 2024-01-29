/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:48:41 by Linsio            #+#    #+#             */
/*   Updated: 2023/11/04 22:04:43 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

int main()
{
	std::vector<int>	v;
	std::list<int>		l;
	std::deque<int>		d;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);

	d.push_back(1);
	d.push_back(2);
	d.push_back(3);
	d.push_back(4);
	d.push_back(5);

	try
	{
		std::cout << *easyfind(v, 3) << std::endl;
		std::cout << *easyfind(l, 4) << std::endl;
		std::cout << *easyfind(d, 4) << std::endl;
		std::cout << *easyfind(v, 6) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}
	return (0);
}