/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:47:41 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/23 16:26:26 by vsanin           ###   ########.fr       */
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
	for (int i = 0; i < 4; i++)
	{
		if (ref.inventory[i])
			inventory[i] = ref.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character& ref)
{
	std::cout << CHAR_COPY_OP;
	if (this != &ref)
	{
		name = ref.name;
		for (int i = 0; i < 4; i++)
		{
			if (inventory[i])
				delete inventory[i];
			if (ref.inventory[i])
				inventory[i] = ref.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	return *this;
}

Character::~Character()
{
	std::cout << CHAR_DESTR;
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i])
			delete inventory[i];
	}
}

std::string const& Character::getName() const { return name; }

void Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			std::cout << "Materia of type '" << m->getType()
					  << "' has been equipped in the inventory slot [" << i << "]\n";
			return;
		}
	}
	std::cout << "Inventory is full, materia not equipped\n";
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
	{
		if (inventory[idx])
		{
			std::cout << "Unequipped materia of type '" << inventory[idx]->getType()
					  << "' at index [" << idx << "]\n";
			inventory[idx] = NULL;
		}
		else
			std::cout << "Can't unequip materia: inventory slot [" << idx << "] empty\n";
	}
	else
		std::cout << "Can't unequip materia: index [" << idx << "] out of range\n";
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx <= 3)
	{
		if (inventory[idx])
			inventory[idx]->use(target);
		else
			std::cout << "Can't use materia at slot [" << idx << "]: empty\n";
	}
	else
		std::cout << "Can't use materia at slot [" << idx << "]: out of range\n";
}
