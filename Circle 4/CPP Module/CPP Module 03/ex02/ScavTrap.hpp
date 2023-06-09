/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:20:22 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/27 20:20:23 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		// Constructors
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &copy);
		// Destructor
		~ScavTrap();
		// Operators
		ScavTrap & operator=(const ScavTrap &assign);
	public:
		unsigned int	getMode(void);
		void			setMode(unsigned int mode);
	public:
		void 			attack(const std::string& target);
		void			guardGate(void);
	private:
		unsigned int	mode;
};

#endif