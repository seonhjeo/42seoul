/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:18:31 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/11 16:52:16 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		this->_materia[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
	for (int i = 0; i < 4; ++i)
	{
		AMateria const *tmp = other.getMateria(i);
		if (tmp != NULL)
			this->_materia[i] = tmp->clone();
		else
			this->_materia[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (this != &other)
	{
		this->~MateriaSource();
		for (int i = 0; i < 4; ++i)
		{
			AMateria const *tmp = other.getMateria(i);
			if (tmp != NULL)
				this->_materia[i] = tmp->clone();
			else
				this->_materia[i] = NULL;
		}
	}
	return (*this);
}

AMateria *MateriaSource::getMateria(int index) const
{
	return (this->_materia[index]);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_materia[i] != NULL)
			delete this->_materia[i];
	}
}

void MateriaSource::learnMateria(AMateria *materia)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_materia[i] == NULL)
		{
			this->_materia[i] = materia;
			return;
		}
	}
    std::cout << "Cannot learn Materia, Inventory is full" << std::endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < 4; ++i)
	{
		if (this->_materia[i] != NULL && this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	}
	return (NULL);
}