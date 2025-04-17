/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:24:01 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/17 19:23:18 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main(void)
{
	{
		std::cout << "Subject tests:" << "\n";
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << std::endl;
		
		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << "\n" << std::endl;
		j->makeSound();
		i->makeSound();
		meta->makeSound();
		
		std::cout << std::endl;
		
		delete meta;
		delete j;
		delete i;
	}
	return 0;
}
