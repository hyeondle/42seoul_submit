/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:28:43 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/28 03:28:57 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"
# include <iostream>
# include <string>

class Cure : public AMateria
{
	public:
		Cure();
		Cure(const Cure &copy);
		~Cure();
		Cure & operator=(const Cure &assign);
		AMateria* clone() const;
		void	use(ICharacter& target);
};

#endif