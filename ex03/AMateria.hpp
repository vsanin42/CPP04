/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:08:49 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/22 20:36:18 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#define AM_DEF_CONSTR	"AMateria:\tDefault constructor called\n"
#define AM_PARAM_CONSTR	"AMateria:\tParametrized constructor called\n"
#define AM_COPY_CONSTR	"AMateria:\tCopy constructor called\n"
#define AM_COPY_OP		"AMateria:\tCopy assignment operator called\n"
#define AM_DESTR		"AMateria:\tDestructor called\n"

#include <string>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;
	public:
		AMateria();
		AMateria(std::string const& type);
		AMateria(const AMateria& ref);
		AMateria& operator=(const AMateria& ref);
		virtual ~AMateria();
		
		std::string const& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif
