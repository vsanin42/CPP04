/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:36:50 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/17 17:45:48 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <string>
#include <iostream>

Dog::Dog() : Animal()
{
	std::cout << D_DEF_CONSTR;
	type = "Dog";
}

Dog::Dog(const std::string& newType) : Animal(newType) { std::cout << D_PARAM_CONSTR; }

Dog::Dog(const Dog& ref) : Animal(ref) { std::cout << D_COPY_CONSTR; }

Dog& Dog::operator=(const Dog& ref)
{
	std::cout << D_COPY_OP;
	if (this != &ref)
	{
		Animal::operator=(ref);
	}
	return *this;
}

Dog::~Dog() { std::cout << D_DESTR; }

void Dog::makeSound(void) const
{
	std::cout << "Type '" << type << "': Woof" << "\n";
}
