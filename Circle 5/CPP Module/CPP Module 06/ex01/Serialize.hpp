/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 16:42:50 by Linsio            #+#    #+#             */
/*   Updated: 2023/10/28 18:47:52 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

# include <cstdint>

struct Data;

class Serialization {
	public:
		Serialization();
		~Serialization();
		Serialization(Serialization const & src);
		Serialization & operator=(Serialization const & rhs);
	public:
		static uintptr_t serialize(Data *ptr);
		static Data * deserialize(uintptr_t raw);
};

#endif