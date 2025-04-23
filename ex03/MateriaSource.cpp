/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:15:42 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/23 16:14:34 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include <string>
#include <iostream>

MateriaSource::MateriaSource()
{
	std::cout << SRC_DEF_CONSTR;
	for (int i = 0; i < 4; i++)
		memory[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& ref)
{
	std::cout << SRC_COPY_CONSTR;
	for (int i = 0; i < 4; i++)
	{
		if (ref.memory[i])
			memory[i] = ref.memory[i]->clone();
		else
			memory[i] = NULL;
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& ref)
{
	std::cout << SRC_COPY_OP;
	if (this != &ref)
	{
		for (int i = 0; i < 4; i++)
		{
			if (memory[i])
				delete memory[i];
			if (ref.memory[i])
				memory[i] = ref.memory[i]->clone();
			else
				memory[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << SRC_DESTR;
	for (int i = 0; i < 4; i++)
	{
		if (memory[i])
			delete memory[i];
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (memory[i] == NULL)
		{
			memory[i] = m;
			std::cout << "Materia of type '" << m->getType()
					  << "' has been saved in the memory slot [" << i << "]\n\n";
			return;
		}
	}
	std::cout << "Memory is full, materia not saved\n";
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (memory[i] && memory[i]->getType() == type)
		{
			std::cout << "Matching materia found, cloning...\n";
			return memory[i]->clone();
		}
	}
	std::cout << "Unknown materia type\n";
	return NULL;
}
