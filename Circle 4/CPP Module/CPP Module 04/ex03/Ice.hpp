/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:28:46 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/28 03:28:56 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"
# include <iostream>
# include <string>

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &copy);
		~Ice();
		Ice & operator=(const Ice &assign);
		AMateria* clone(void) const;
		void	use(ICharacter& target);

};

#endif