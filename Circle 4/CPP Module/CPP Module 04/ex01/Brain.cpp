/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:27:56 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/28 03:29:15 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

// Constructors
Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
	std::cout << "\e[0;33mDefault Constructor called of Brain\e[0m" << std::endl;
}
Brain::Brain(const Brain &copy)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	std::cout << "\e[0;33mCopy Constructor called of Brain\e[0m" << std::endl;
}
// Destructor
Brain::~Brain()
{
	std::cout << "\e[0;31mDestructor called of Brain\e[0m" << std::endl;
}
// Operators
Brain & Brain::operator=(const Brain &assign)
{
	if (this != &assign)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = assign.ideas[i];
	}
	std::cout << "\e[0;33mOperator= called of Brain\e[0m" << std::endl;
	return *this;
}
std::string Brain::getIdeas(int n) const
{
	return this->ideas[n];
}
void	Brain::setIdeas(int n, std::string idea)
{
	this->ideas[n] = idea;
}