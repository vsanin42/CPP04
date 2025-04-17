/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:37:01 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/17 17:42:17 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#define D_DEF_CONSTR	"Dog:\tDefault constructor called\n"
#define D_PARAM_CONSTR	"Dog:\tParametrized constructor called\n"
#define D_COPY_CONSTR	"Dog:\tCopy constructor called\n"
#define D_COPY_OP		"Dog:\tCopy assignment operator called\n"
#define D_DESTR			"Dog:\tDestructor called\n"

#include "Animal.hpp"
#include <string>

class Dog : public Animal
{
	public:
		Dog();
		Dog(const std::string& newType);
		Dog(const Dog& ref);
		Dog& operator=(const Dog& ref);
		~Dog();

		void makeSound(void) const;
};

#endif
