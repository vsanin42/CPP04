/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:37:01 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/18 11:44:18 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#define WA_DEF_CONSTR	"WrongAnimal:\tDefault constructor called\n"
#define WA_PARAM_CONSTR	"WrongAnimal:\tParametrized constructor called\n"
#define WA_COPY_CONSTR	"WrongAnimal:\tCopy constructor called\n"
#define WA_COPY_OP		"WrongAnimal:\tCopy assignment operator called\n"
#define WA_DESTR		"WrongAnimal:\tDestructor called\n"

#include <string>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const std::string& newType);
		WrongAnimal(const WrongAnimal& ref);
		WrongAnimal& operator=(const WrongAnimal& ref);
		virtual ~WrongAnimal();

		void makeSound(void) const;
		const std::string& getType(void) const;
};

#endif
