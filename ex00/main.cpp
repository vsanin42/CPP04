/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:24:01 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/18 12:16:31 by vsanin           ###   ########.fr       */
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
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << std::endl;
		
		std::cout << meta->getType() << " " << std::endl;
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
	{
		std::cout << "~~~~~~~~OCCF tests:~~~~~~~~" << "\n";
		Animal a("aaaaa");
		Dog b("bbbbb");
		Cat c("ccccc");
		
		std::cout << std::endl;
		
		std::cout << a.getType() << std::endl;
		std::cout << b.getType() << std::endl;
		std::cout << c.getType() << "\n" << std::endl;

		a.makeSound();
		b.makeSound();
		c.makeSound();
		
		Animal a2(a);
		Dog b2(b);
		Cat c2(c);
		
		std::cout << std::endl;

		std::cout << a2.getType() << std::endl;
		std::cout << b2.getType() << std::endl;
		std::cout << c2.getType() << "\n" << std::endl;

		a2.makeSound();
		b2.makeSound();
		c2.makeSound();

		std::cout << std::endl;

		a = a2;
		b = b2;
		c = c2;
		
		std::cout << std::endl;

		std::cout << a.getType() << std::endl;
		std::cout << b.getType() << std::endl;
		std::cout << c.getType() << "\n" << std::endl;

		a.makeSound();
		b.makeSound();
		c.makeSound();
		
		std::cout << std::endl;
	}
	{
		std::cout << "~~~~~~~~Calls via pointers tests:~~~~~~~~" << "\n";

		Cat* c = new Cat("chimi");
		Dog* d = new Dog("dawg");

		std::cout << std::endl;
		
		std::cout << c->getType() << std::endl;
		std::cout << d->getType() << std::endl;
		
		std::cout << std::endl;
		
		c->makeSound();
		d->makeSound();
		
		std::cout << std::endl;
		
		delete c;
		delete d;
	}
	{
		std::cout << "~~~~~~~~Object slicing tests:~~~~~~~~" << "\n";

		Cat c("chimi");
		Animal a = c;
		
		std::cout << std::endl;

		std::cout << c.getType() << std::endl;
		std::cout << a.getType() << std::endl;
		
		std::cout << std::endl;
		
		c.makeSound();
		a.makeSound();
		
		std::cout << std::endl;
	}
	{
		std::cout << "~~~~~~~~WrongAnimal/WrongCat tests:~~~~~~~~" << "\n";
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		
		std::cout << std::endl;
		
		std::cout << meta->getType() << " " << std::endl;
		std::cout << i->getType() << " " << "\n" << std::endl;
		i->makeSound();
		meta->makeSound();
		
		std::cout << std::endl;

		const WrongCat* cat = static_cast<const WrongCat*>(i);
		cat->makeSound();
		
		std::cout << std::endl;
		
		delete meta;
		delete i;
	}
	return 0;
}
