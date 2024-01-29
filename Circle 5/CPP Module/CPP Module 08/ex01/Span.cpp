/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:09:48 by Linsio            #+#    #+#             */
/*   Updated: 2023/11/04 22:04:50 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <cstdlib>

Span::Span():_n(0){}
Span::~Span(){}
Span::Span(const Span &copy) : _n(copy._n), _numbers(copy._numbers) {}
Span & Span::operator=(const Span &assign)
{
	if (this != &assign)
	{
		_numbers = assign._numbers;
		_n = assign._n;
	}
	return *this;
}

Span::Span(unsigned int N) : _n(N) {}

void Span::testNumbers(void)
{
	for (unsigned int i = 0; i < _n; i++)
		addNumber(rand());
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _n)
		throw FullException();
	_numbers.push_back(number);
}

int Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw TooLowException();

	std::vector<int> sorted_numbers(_numbers);
	std::sort(sorted_numbers.begin(), sorted_numbers.end());

	int shortest = std::numeric_limits<int>::max();
	for (std::vector<int>::iterator it = sorted_numbers.begin(); it != sorted_numbers.end() - 1; ++it)
	{
		int span = *(it + 1) - *it;
		if (span < shortest)
		{
			shortest = span;
		}
	}
	return shortest;
}

int Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw TooLowException();

	std::vector<int> sorted_numbers(_numbers);
	std::sort(sorted_numbers.begin(), sorted_numbers.end());

	return *(sorted_numbers.end() - 1) - *sorted_numbers.begin();
}

const char* Span::FullException::what() const throw()
{
	return "Can't add more elements. Already full";
}

const char* Span::TooLowException::what() const throw()
{
	return "You have to add more input to find Spans.";
}
