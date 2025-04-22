/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:24:25 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/22 21:56:25 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>
#include <typeinfo>

AMateria::AMateria() : type("") { std::cout << AM_DEF_CONSTR; }

AMateria::AMateria(std::string const& type) : type(type) { std::cout << AM_PARAM_CONSTR; }

AMateria::AMateria(const AMateria& ref) : type(ref.type) { std::cout << AM_COPY_CONSTR; }

AMateria& AMateria::operator=(const AMateria& ref)
{
	if (typeid(*this) != typeid(ref))
	{
		std::cout << "Cannot perform copy assignment on mismatched types, result unchanged\n";
	}
	else
	{
		std::cout << AM_COPY_OP;
		if (this != &ref)
		{
			type = ref.type;
		}
	}
	return *this;
}

AMateria::~AMateria() { std::cout << AM_DESTR; }

std::string const& AMateria::getType() const { return type; }

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "get real\n";
}
