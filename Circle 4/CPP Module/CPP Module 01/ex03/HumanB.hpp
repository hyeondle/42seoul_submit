/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 23:51:13 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/23 00:04:56 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon *weapon;
		std::string name;
	public:
		HumanB(std::string name);
		void attack();
		void setWeapon(Weapon &weapon);
};