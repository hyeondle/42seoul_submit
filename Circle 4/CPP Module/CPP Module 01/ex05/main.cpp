/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 12:01:17 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/24 12:07:21 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "input error" << std::endl;
		return 1;
	}

	std::string level = argv[1];
	Harl a;
	a.complain(level);
}