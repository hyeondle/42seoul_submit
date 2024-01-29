/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:09:13 by Linsio            #+#    #+#             */
/*   Updated: 2023/11/03 16:50:18 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		T				*_array;
		unsigned int	_length;

	public:
		Array();
		Array(unsigned int n);
		Array(Array const &src);
		~Array();

		Array	&operator=(Array const &rhs);
		T		&operator[](unsigned int i) const;
		unsigned int	size(void) const;

		class OutOfLimitsException: public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

template <typename T>	Array<T>::Array(): _array(NULL), _length(0){}
template <typename T>	Array<T>::Array(unsigned int n): _array(new T[n]), _length(n){}
template <typename T>	Array<T>::Array(Array const &src){	*this = src;	}
template <typename T>	Array<T>::~Array()	{	delete [] this->_array;	}
template <typename T>	Array<T>	&Array<T>::operator=(Array const &rhs)
{
	if (this != &rhs)
	{
		this->_array = new T[rhs._length];
		for (unsigned int i = 0; i < rhs._length; i++)
			this->_array[i] = rhs._array[i];
		this->_length = rhs._length;
	}
	return (*this);
}
template <typename T>	T	&Array<T>::operator[](unsigned int i) const
{
	if (i >= this->_length)
		throw Array::OutOfLimitsException();
	return (this->_array[i]);
}
template <typename T>	unsigned int	Array<T>::size(void) const
{
	return (this->_length);
}
template <typename T>	const char	*Array<T>::OutOfLimitsException::what() const throw()
{
	return ("Out of range");
}

#endif