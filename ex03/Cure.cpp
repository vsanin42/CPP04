/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:40:19 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/23 11:54:56 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"
#include "Cure.hpp"
#include <iostream>

Cure::Cure() : AMateria("cure") { std::cout << CURE_DEF_CONSTR; }

Cure::Cure(std::string const& type) : AMateria(type) { std::cout << CURE_PARAM_CONSTR; } // needed?

Cure::Cure(const Cure& ref) : AMateria(ref) { std::cout << CURE_COPY_CONSTR; }

Cure& Cure::operator=(const Cure& ref)
{
	std::cout << CURE_COPY_OP;
	if (this != &ref)
	{
		AMateria::operator=(ref);
	}
	return *this;
}

Cure::~Cure() { std::cout << CURE_DESTR; }

AMateria* Cure::clone() const
{
	AMateria* newCure = new Cure(*this);
	return newCure;
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
