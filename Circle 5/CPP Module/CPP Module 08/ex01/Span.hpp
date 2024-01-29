/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 04:34:09 by Linsio            #+#    #+#             */
/*   Updated: 2023/11/04 22:04:54 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> _numbers;

	public:
		Span();
		~Span();
		Span(const Span &copy);
		Span & operator=(const Span &assign);

	public:
		Span(unsigned int N);
		void testNumbers(void);
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();

		class FullException : public std::exception
		{
			virtual const char* what() const throw();
		};

		class TooLowException : public std::exception
		{
			virtual const char* what() const throw();
		};
};

#endif
