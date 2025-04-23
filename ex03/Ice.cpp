/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:40:19 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/23 17:38:07 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"
#include "Ice.hpp"
#include <iostream>

Ice::Ice() : AMateria("ice") { std::cout << ICE_DEF_CONSTR; }

Ice::Ice(std::string const& type) : AMateria(type) { std::cout << ICE_PARAM_CONSTR; }

Ice::Ice(const Ice& ref) : AMateria(ref) { std::cout << ICE_COPY_CONSTR; }

Ice& Ice::operator=(const Ice& ref)
{
	std::cout << ICE_COPY_OP;
	if (this != &ref)
	{
		AMateria::operator=(ref);
	}
	return *this;
}

Ice::~Ice() { std::cout << ICE_DESTR; }

AMateria* Ice::clone() const
{
	AMateria* newIce = new Ice(*this);
	return newIce;
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
