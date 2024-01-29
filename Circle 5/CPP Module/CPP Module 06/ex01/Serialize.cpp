/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:47:58 by Linsio            #+#    #+#             */
/*   Updated: 2023/10/28 18:47:50 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialize.hpp"
#include "Data.hpp"

Serialization::Serialization(){}
Serialization::~Serialization(){}
Serialization::Serialization(Serialization const & src){*this = src;}
Serialization & Serialization::operator=(Serialization const & rhs){(void)rhs; return *this;}

uintptr_t Serialization::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data * Serialization::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
