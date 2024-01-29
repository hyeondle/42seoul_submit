/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:49:51 by Linsio            #+#    #+#             */
/*   Updated: 2023/10/28 18:47:48 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"
#include "Data.hpp"
#include <iostream>

int main()
{
	Data *test = new Data();
	test->a = 1;
	test->b = 285.3f;
	test->c = 42.424242;

	uintptr_t	cubeA;
	Data*		cubeB;

	cubeA = Serialization::serialize(test);
	cubeB = Serialization::deserialize(cubeA);

	std::cout << "Test" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "Origianl	: " << test->a << ", " << test->b << ", " << test->c << std::endl;
	std::cout << "Casted		: " << cubeB->a << ", " << cubeB->b << ", " << cubeB->c << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	std::cout << "Original pointer is equals to casted pointer ?" << std::endl;
	if (test == cubeB)
		std::cout << "Yes" << std::endl;
	else
		std::cout << "No" << std::endl;

	delete(test);

	return (0);
}