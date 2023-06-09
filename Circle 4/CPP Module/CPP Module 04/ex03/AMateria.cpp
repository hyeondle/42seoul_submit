/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:28:37 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/28 03:28:59 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	this->type = "NULL";
}
AMateria::AMateria(std::string const & type)
{
	this->type = type;
}
AMateria::AMateria(const AMateria &copy)
{
	this->type = copy.type;
}
AMateria::~AMateria()
{
}
AMateria & AMateria::operator=(const AMateria &assign)
{
	if (this != &assign)
		this->type = assign.type;
	return *this;
}
std::string const & AMateria::getType() const
{
	return this->type;
}
void AMateria::use(ICharacter &target)
{
	std::cout << "* is undefine Material. Nothing happend on " << target.getName() << " *" << std::endl;
}