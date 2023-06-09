/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <st.linsio@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 23:30:42 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/23 00:03:58 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon *weapon;
		std::string name;
	public:
		HumanA(std::string name, Weapon &weapon);
		void attack();
};