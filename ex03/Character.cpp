/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:47:41 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/23 10:55:19 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

Character::Character() : name("")
{
	std::cout << CHAR_DEF_CONSTR;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(std::string const& name) : name(name)
{
	std::cout << CHAR_PARAM_CONSTR;
	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

Character::Character(const Character& ref) : name(ref.name)
{
	std::cout << CHAR_COPY_CONSTR;
	// deep copy
}

Character& Character::operator=(const Character& ref)
{
	std::cout << CHAR_COPY_OP;
	if (this != &ref)
	{
		name = ref.name;
		// deep copy
	}
	return *this;
}

Character::~Character() { std::cout << CHAR_DESTR; }

std::string const& Character::getName() const { return name; }

void Character::equip(AMateria* m)
{
	int i;
	for (i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			std::cout << "Materia of type '" << m->getType()
					  << "' has been equipped in the inventory slot [" << i << "]\n";
		}
	}
	if (i == 4)
		std::cout << "Inventory is full, materia not equipped\n";
}

void Character::unequip(int idx)
{
	// tdo something else?
	if (idx >= 0 && idx <= 3)
		inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	// todo something else?
	if (idx >= 0 && idx <= 3)
		inventory[idx]->use(target);
}
