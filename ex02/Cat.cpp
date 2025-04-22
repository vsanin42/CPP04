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

Cat::Cat() : Animal(), brain(new Brain())
{
	std::cout << C_DEF_CONSTR;
	type = "Cat";
}

Cat::Cat(const std::string& newType) : Animal(newType), brain(new Brain())
{
	std::cout << C_PARAM_CONSTR;
}

Cat::Cat(const Cat& ref) : Animal(ref), brain(new Brain(*(ref.brain)))
{
	std::cout << C_COPY_CONSTR;
}

Cat& Cat::operator=(const Cat& ref)
{
	std::cout << C_COPY_OP;
	if (this != &ref)
	{
		*brain = *(ref.brain);
		Animal::operator=(ref);
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << C_DESTR;
	delete brain;
}

void Cat::makeSound(void) const
{
	std::cout << "Type '" << type << "': Meow" << "\n";
}

const Brain* Cat::getBrain(void) const { return brain; }
