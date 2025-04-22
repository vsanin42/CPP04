/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:37:39 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/22 20:00:19 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#define ICE_DEF_CONSTR		"Ice:\tDefault constructor called\n"
#define ICE_PARAM_CONSTR	"Ice:\tParametrized constructor called\n"
#define ICE_COPY_CONSTR		"Ice:\tCopy constructor called\n"
#define ICE_COPY_OP			"Ice:\tCopy assignment operator called\n"
#define ICE_DESTR			"Ice:\tDestructor called\n"

#include "AMateria.hpp"
#include <string>

class Ice : public AMateria
{
	public:
		Ice();
		Ice(std::string const& type);
		Ice(const Ice& ref);
		Ice& operator=(const Ice& ref);
		~Ice();
		
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
