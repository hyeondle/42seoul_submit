/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:26:49 by hyeondle          #+#    #+#             */
/*   Updated: 2023/10/27 12:14:49 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exception>
#include <iostream>
#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat a;
		Bureaucrat b("Jam", 3);
		Bureaucrat c("Tim", 148);

		std::cout << a << b << c;
		b.setName("Jaimg");
		b.increament();
		std::cout << b;
		b.increament();
		std::cout << b;
		b.decreament();
		std::cout << b;
		c.decreament();
		c.decreament();
		c.decreament();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}