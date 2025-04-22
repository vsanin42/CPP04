/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:36:50 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/18 10:03:36 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <string>
#include <iostream>

Animal::Animal() : type("Animal") { std::cout << "\n" << A_DEF_CONSTR; }

Animal::Animal(const std::string& newType) : type(newType) { std::cout << "\n" << A_PARAM_CONSTR; }

Animal::Animal(const Animal& ref) : type(ref.type) { std::cout << "\n" << A_COPY_CONSTR; }

Animal& Animal::operator=(const Animal& ref)
{
	std::cout << A_COPY_OP;
	if (this != &ref)
	{
		type = ref.type;
	}
	return *this;
}

Animal::~Animal() { std::cout << A_DESTR << "\n"; }

void Animal::makeSound(void) const
{
	std::cout << "Type '" << type << "': AAA" << "\n";
}

const std::string& Animal::getType(void) const { return type;}
