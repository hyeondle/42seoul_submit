/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:47:50 by Linsio            #+#    #+#             */
/*   Updated: 2023/11/04 22:04:35 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>

template <typename T>
typename T::iterator	easyfind(T &container, int n)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw std::exception();
	return (it);
}

#endif