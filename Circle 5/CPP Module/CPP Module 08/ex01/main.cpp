/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:18:40 by Linsio            #+#    #+#             */
/*   Updated: 2023/11/04 22:04:47 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <iostream>

int main() {
	srand(static_cast<unsigned int>(time(0)));
	Span sp = Span(5);
	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	Span sp2 = Span(15);
	try {
		sp2.addNumber(30);
		sp2.addNumber(2);
		sp2.addNumber(7);
		sp2.addNumber(11);
		sp2.addNumber(29);
		sp2.addNumber(53);
		sp2.addNumber(24);
		sp2.addNumber(55);
		sp2.addNumber(74);
		sp2.addNumber(49);
		sp2.addNumber(1);
		sp2.addNumber(35);
		sp2.addNumber(36);
		sp2.addNumber(12);
		sp2.addNumber(101);
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	Span sp3 = Span(15000);
	try {
		sp3.testNumbers();
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

