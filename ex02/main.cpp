/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:24:01 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/22 18:43:24 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main(void)
{
	{
		std::cout << "~~~~~~~~Subject tests:~~~~~~~~" << "\n";
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << "\n" << "Dog ideas:" << std::endl;
		const Dog* dog = static_cast<const Dog*>(j);
		dog->getBrain()->showIdeas();
		std::cout << std::endl;
		
		std::cout << "Cat ideas:" << std::endl;
		const Cat* cat = static_cast<const Cat*>(j);
		cat->getBrain()->showIdeas();
		std::cout << std::endl;

		delete j;
		delete i;
	}
	{
		std::cout << "~~~~~~~~Brain tests:~~~~~~~~" << "\n";
		std::cout << std::endl;
		Brain a;
		
		a.showIdeas();
		std::cout << std::endl;

		Brain b(a);
		b.showIdeas();
		std::cout << std::endl;

		Brain c; 
		c = b;
		c.showIdeas();
		std::cout << std::endl;
	}
	{
		std::cout << "\n~~~~~~~~OCCF tests:~~~~~~~~" << "\n";
		Dog d("dawg");
		Cat c("chimi");
		
		Dog d2(d);
		Cat c2(c);

		std::cout << std::endl;

		d = d2;
		std::cout << std::endl;
		c = c2;
		std::cout << std::endl;
	}
	{
		std::cout << "~~~~~~~~Animal array tests:~~~~~~~~" << "\n";
		Animal* arr[6];

		int i = 0;
		while (i < 3)
			arr[i++] = new Dog();
		while (i < 6)
			arr[i++] = new Cat();
			
		std::cout << std::endl;
		arr[2]->makeSound();
		arr[5]->makeSound();
			
		std::cout << "\nArray types:" << std::endl;
		for (int j = 0; j < 6; j++)
			std::cout << arr[j]->getType() << std::endl;
		std::cout << std::endl;
		
		while (i > 0)
			delete arr[--i];
	}
	{
		std::cout << "~~~~~~~~Abstract tests:~~~~~~~~" << "\n";
		// Animal a; // - not allowed

		// Animal a("aaa"); // - not allowed
		
		// Dog dawg("dawg");
		// Animal aw = dawg; // - not allowed
		Animal* ptr = new Dog();
		std::cout << ptr->getType() << std::endl;
		ptr->makeSound();
		delete ptr;
	}
	return 0;
}
