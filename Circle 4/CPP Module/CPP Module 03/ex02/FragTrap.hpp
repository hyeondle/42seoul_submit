/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:20:13 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/27 20:20:14 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
# include <iostream>
# include <string>

class FragTrap : public ClapTrap
{
	public:
		// Constructors
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &copy);
		// Destructor
		~FragTrap();
		// Operators
		FragTrap & operator=(const FragTrap &assign);
	public:
		void	highFivesGuys(void);
	private:
};

#endif