/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 14:04:26 by Linsio            #+#    #+#             */
/*   Updated: 2023/11/03 16:50:04 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main()
{
	int		array[] = {1, 2, 3, 4, 5};
	std::string	array2[] = {"a", "b", "c", "d", "e"};
	int		array3[] = {10,8,6,4,2};

	void (*printFunction)(int const &) = print;

	iter(array, 5, print<int>);
	iter(array2, 5, print<std::string>);
	iter(array3, 5, printFunction);

	return (0);
}


