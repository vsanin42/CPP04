/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 21:24:01 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/23 16:12:46 by vsanin           ###   ########.fr       */
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
		std::cout << "~~~~~~~~Unequip tests:~~~~~~~~\n\n";
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
	return 0;
}
