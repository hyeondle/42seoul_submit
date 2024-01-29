/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 12:42:08 by Linsio            #+#    #+#             */
/*   Updated: 2023/11/03 16:50:07 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

// template <typename T>
// void	iter(T *array, int length, void (*f)(T const &))
// {
// 	for (int i = 0; i < length; i++)
// 		f(array[i]);
// }

template <typename T, typename F>
void iter(T *array, int length, F function)
{
    for (int i = 0; i < length; i++)
        function(array[i]);
}

template <typename T>
void	print(T const &i)
{
	std::cout << i << std::endl;
}

#endif