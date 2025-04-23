/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:24:01 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/23 17:35:00 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "IMateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include <iostream>

int main(void)
{
	{
		std::cout << "~~~~~~~~Subject tests:~~~~~~~~\n\n";
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		
		ICharacter* me = new Character("me");
		
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		std::cout << std::endl;
		
		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cout << std::endl;
		
		ICharacter* bob = new Character("bob");
		
		std::cout << std::endl;
		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << std::endl;
		
		delete bob;
		delete me;
		delete src;
	}
	{
		std::cout << "~~~~~~~~Equip/Unequip tests:~~~~~~~~\n\n";
		ICharacter* bob = new Character("bob");
		
		std::cout << std::endl;
		bob->unequip(5);
		bob->unequip(-1);
		bob->unequip(2);
		std::cout << std::endl;
		
		AMateria* ice = new Ice();
		AMateria* cure = new Cure();
		AMateria* ice2 = new Ice();
		AMateria* cure2 = new Cure();

		AMateria* extraIce = new Ice();
		
		std::cout << std::endl;
		bob->equip(ice);
		bob->equip(cure);
		bob->equip(ice2);
		bob->equip(cure2);
		bob->equip(extraIce);
		std::cout << std::endl;
		
		bob->unequip(0);
		bob->unequip(1);
		bob->unequip(2);
		bob->unequip(3);
		
		std::cout << std::endl;
		delete ice;
		delete cure;
		delete ice2;
		delete cure2;
		
		delete extraIce;
		delete bob;
	}
	{
		std::cout << "~~~~~~~~MateriaSource tests:~~~~~~~~\n\n";
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice("notIce"));
		src->learnMateria(new Cure("notCure"));
		
		AMateria* extra = new Ice("extra");
		std::cout << std::endl;
		src->learnMateria(extra);
		std::cout << std::endl;
		
		AMateria* sample = src->createMateria("extra");
		if (sample == NULL)
			std::cout << "createMateria returned NULL\n\n";

		sample = src->createMateria("notIce");
		std::cout << "Created materia from memory with type '" << sample->getType() << "'\n";
		
		std::cout << std::endl;
		delete sample;
		delete extra;
		delete src;
	}
	{
		std::cout << "~~~~~~~~Use (ICharacter) tests:~~~~~~~~\n\n";
		AMateria* ice = new Ice();
		AMateria* cure = new Cure();
		ICharacter* biba = new Character("biba");
		ICharacter* boba = new Character("boba");

		std::cout << std::endl;
		biba->equip(ice);
		biba->equip(cure);
		std::cout << std::endl;
		
		biba->use(5, *boba);
		biba->use(2, *boba);
		biba->use(0, *boba);
		biba->use(1, *boba);
		
		std::cout << std::endl;
		biba->unequip(1);
		biba->use(1, *boba);
		std::cout << std::endl;
		
		delete cure;
		delete biba;
		delete boba;
	}
	{
		std::cout << "~~~~~~~~OCCF tests - Character:~~~~~~~~\n\n";
		Character a;
		Character b("biba");
		Character c(b);
		Character d;
		d = c;

		std::cout << "a: " << a.getName() << "\n";
		std::cout << "b: " << b.getName() << "\n";
		std::cout << "c: " << c.getName() << "\n";
		std::cout << "d: " << d.getName() << "\n";
	}
	{
		std::cout << "~~~~~~~~OCCF tests - MateriaSource:~~~~~~~~\n\n";
		MateriaSource a;
		MateriaSource b(a);
		MateriaSource c;
		c = b;
	}
	{
		std::cout << "~~~~~~~~OCCF tests - Ice:~~~~~~~~\n\n";
		Ice a;
		Ice b("biba");
		Ice c(b);
		Ice d;
		d = c;

		std::cout << "a: " << a.getType() << "\n";
		std::cout << "b: " << b.getType() << "\n";
		std::cout << "c: " << c.getType() << "\n";
		std::cout << "d: " << d.getType() << "\n";
	}
	{
		std::cout << "~~~~~~~~OCCF tests - Cure:~~~~~~~~\n\n";
		Cure a;
		Cure b("biba");
		Cure c(b);
		Cure d;
		d = c;

		std::cout << "a: " << a.getType() << "\n";
		std::cout << "b: " << b.getType() << "\n";
		std::cout << "c: " << c.getType() << "\n";
		std::cout << "d: " << d.getType() << "\n";
	}
	{
		std::cout << "~~~~~~~~Copy assignment - Ice/Cure:~~~~~~~~\n\n";
		AMateria* i = new Ice();
		AMateria* c = new Cure();
		
		std::cout << std::endl;
		*i = *c;
		std::cout << std::endl;
		
		std::cout << "i: " << i->getType() << "\n";
		std::cout << "c: " << c->getType() << "\n\n";

		delete i;
		delete c;
	}
	return 0;
}
