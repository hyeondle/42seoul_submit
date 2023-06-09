/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:28:51 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/28 03:28:54 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i) materia[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i < 4; ++i)
	{
        if (copy.materia[i])
			this->materia[i] = copy.materia[i]->clone();
        else
            this->materia[i] = nullptr;
    }
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
        if (this->materia[i])
            delete this->materia[i];
    }
}

MateriaSource & MateriaSource::operator=(const MateriaSource &assign)
{
	if (this != &assign)
	{
        for (int i = 0; i < 4; ++i)
		{
            if (this->materia[i])
                delete this->materia[i];
            if (assign.materia[i])
                this->materia[i] = assign.materia[i]->clone();
            else
                this->materia[i] = nullptr;
        }
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; ++i)
	{
        if (materia[i] == nullptr)
		{
            materia[i] = m->clone();
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; ++i)
	{
        if (materia[i] != nullptr && materia[i]->getType() == type)
            return materia[i]->clone();
    }
    return 0;
}