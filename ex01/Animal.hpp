/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:37:01 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/22 13:23:39 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#define A_DEF_CONSTR	"Animal:\tDefault constructor called\n"
#define A_PARAM_CONSTR	"Animal:\tParametrized constructor called\n"
#define A_COPY_CONSTR	"Animal:\tCopy constructor called\n"
#define A_COPY_OP		"Animal:\tCopy assignment operator called\n"
#define A_DESTR			"Animal:\tDestructor called\n"

#include <string>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const std::string& newType);
		Animal(const Animal& ref);
		Animal& operator=(const Animal& ref);
		virtual ~Animal();

		virtual void makeSound(void) const;
		const std::string& getType(void) const;
};

#endif
