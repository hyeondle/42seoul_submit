/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 17:24:31 by Linsio            #+#    #+#             */
/*   Updated: 2023/11/04 22:05:00 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_HPP
# define MUTANT_HPP

#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack<T>& other);
		MutantStack<T>& operator=(const MutantStack<T>& other);
		virtual ~MutantStack();
	public:
		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;
	public:
		iterator				begin();
		iterator				end();
		const_iterator			begin() const;
		const_iterator			end() const;
		reverse_iterator		rbegin();
		reverse_iterator		rend();
		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;
};

template<typename T>	MutantStack<T>::MutantStack() : std::stack<T>() {}
template<typename T>	MutantStack<T>::MutantStack(const MutantStack<T>& other) : std::stack<T>(other) {}
template<typename T>	MutantStack<T>::~MutantStack() {}
template<typename T>	MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& other)
{
	if (this != &other) {
		std::stack<T>::operator=(other);
	}
	return *this;
}

template<typename T>	typename MutantStack<T>::iterator MutantStack<T>::begin()						{	return this->c.begin();	}
template<typename T>	typename MutantStack<T>::iterator MutantStack<T>::end()							{	return this->c.end();	}
template<typename T>	typename MutantStack<T>::const_iterator MutantStack<T>::begin() const			{	return this->c.begin();	}
template<typename T>	typename MutantStack<T>::const_iterator MutantStack<T>::end() const				{	return this->c.end();	}
template<typename T>	typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()				{	return this->c.rbegin();}
template<typename T>	typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()				{	return this->c.rend();	}
template<typename T>	typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const	{	return this->c.rbegin();}
template<typename T>	typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const	{	return this->c.rend();	}

#endif