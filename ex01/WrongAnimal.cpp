/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:36:50 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/18 11:56:20 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal") { std::cout << "\n" << WA_DEF_CONSTR; }

WrongAnimal::WrongAnimal(const std::string& newType) : type(newType) { std::cout << "\n" << WA_PARAM_CONSTR; }

WrongAnimal::WrongAnimal(const WrongAnimal& ref) : type(ref.type) { std::cout << "\n" << WA_COPY_CONSTR; }

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ref)
{
	std::cout << WA_COPY_OP;
	if (this != &ref)
	{
		type = ref.type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() { std::cout << WA_DESTR << "\n"; }

void WrongAnimal::makeSound(void) const
{
	std::cout << "Type '" << type << "': WrongAnimal sound EEEEEEEEEEEEEEE" << "\n";
}

const std::string& WrongAnimal::getType(void) const { return type;}
