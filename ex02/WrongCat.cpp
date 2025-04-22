/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:36:50 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/18 11:56:37 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <string>
#include <iostream>

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << WC_DEF_CONSTR;
	type = "WrongCat";
}

WrongCat::WrongCat(const std::string& newType) : WrongAnimal(newType) { std::cout << WC_PARAM_CONSTR; }

WrongCat::WrongCat(const WrongCat& ref) : WrongAnimal(ref) { std::cout << WC_COPY_CONSTR; }

WrongCat& WrongCat::operator=(const WrongCat& ref)
{
	std::cout << WC_COPY_OP;
	if (this != &ref)
	{
		WrongAnimal::operator=(ref);
	}
	return *this;
}

WrongCat::~WrongCat() { std::cout << WC_DESTR; }

void WrongCat::makeSound(void) const
{
	std::cout << "Type '" << type << "': WrongMeow" << "\n";
}
