/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:37:01 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/17 17:42:17 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#define C_DEF_CONSTR	"Cat:\tDefault constructor called\n"
#define C_PARAM_CONSTR	"Cat:\tParametrized constructor called\n"
#define C_COPY_CONSTR	"Cat:\tCopy constructor called\n"
#define C_COPY_OP		"Cat:\tCopy assignment operator called\n"
#define C_DESTR			"Cat:\tDestructor called\n"

#include "Animal.hpp"
#include <string>

class Cat : public Animal
{
	public:
		Cat();
		Cat(const std::string& newType);
		Cat(const Cat& ref);
		Cat& operator=(const Cat& ref);
		~Cat();

		void makeSound(void) const;
};

#endif
