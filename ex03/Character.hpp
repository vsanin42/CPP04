/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:22:14 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/23 15:23:15 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#define CHAR_DEF_CONSTR		"Character:\tDefault constructor called\n"
#define CHAR_PARAM_CONSTR	"Character:\tParametrized constructor called\n"
#define CHAR_COPY_CONSTR	"Character:\tCopy constructor called\n"
#define CHAR_COPY_OP		"Character:\tCopy assignment operator called\n"
#define CHAR_DESTR			"Character:\tDestructor called\n\n"

#include "ICharacter.hpp"
#include <string>

class AMateria;

class Character : public ICharacter
{
	private:
		std::string name;
		AMateria* inventory[4];
		// AMateria* garbage[1000];
	public:
		Character();
		Character(std::string const& name);
		Character(const Character& ref);
		Character& operator=(const Character& ref);
		~Character();

		std::string const& getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
