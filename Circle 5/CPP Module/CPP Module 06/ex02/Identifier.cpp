/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 17:12:49 by Linsio            #+#    #+#             */
/*   Updated: 2023/10/28 18:48:47 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identifier.hpp"
#include <cstdlib>
#include <iostream>

Base * generate()
{
	int i = rand() % 3;
	if (i == 0)
		return (new A);
	else if (i == 1)
		return (new B);
	else
		return (new C);
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
    try {
        A& refToA = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
		(void)refToA;
        return;
    } catch(...) {}

    try {
        B& refToB = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
		(void)refToB;
        return;
    } catch(...) {}

    try {
        C& refToC = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
		(void)refToC;
        return;
    } catch(...) {}

    std::cout << "Unknown type" << std::endl;
}