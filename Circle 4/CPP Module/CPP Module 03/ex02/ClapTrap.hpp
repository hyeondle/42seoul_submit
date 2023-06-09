/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:20:18 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/27 20:20:19 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	public:
		// Constructors
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &copy);
		// Destructor
		virtual ~ClapTrap();
		// Operators
		ClapTrap & operator=(const ClapTrap &assign);
	public:
		void			displayState(void);
		int				statecheck(void);
		virtual void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
	public:
		void			setHitPoint(unsigned int amount);
		void			setEnergyPoint(unsigned int amount);
		void			setAttackDamage(unsigned int amount);
		void			setName(std::string name);
		unsigned int	getHitPoint(void);
		unsigned int	getEnergyPoint(void);
		unsigned int	getAttackDamage(void);
		std::string		getName(void);
	protected:
		std::string		name;
		unsigned int	hitPoint;
		unsigned int	energyPoint;
		unsigned int	attackDamage;
	protected:
		void			dead(void);
		void			noEnergy(void);
};

#endif