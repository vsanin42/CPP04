/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:36:50 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/17 17:45:48 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <string>
#include <iostream>

Cat::Cat() : Animal("Cat") { std::cout << C_DEF_CONSTR; }

Cat::Cat(const std::string& newType) : Animal(newType) { std::cout << C_PARAM_CONSTR; }

Cat::Cat(const Cat& ref) : Animal(ref) { std::cout << C_COPY_CONSTR; }

Cat& Cat::operator=(const Cat& ref)
{
	std::cout << C_COPY_OP;
	if (this != &ref)
	{
		Animal::operator=(ref);
	}
	return *this;
}

Cat::~Cat() { std::cout << C_DESTR; }

void Cat::makeSound(void) const
{
	std::cout << "Type '" << type << "': Meow" << "\n";
}
