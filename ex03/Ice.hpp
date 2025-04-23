/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:37:39 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/23 13:22:53 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#define ICE_DEF_CONSTR		"Ice:\t\tDefault constructor called\n"
#define ICE_PARAM_CONSTR	"Ice:\t\tParametrized constructor called\n"
#define ICE_COPY_CONSTR		"Ice:\t\tCopy constructor called\n"
#define ICE_COPY_OP			"Ice:\t\tCopy assignment operator called\n"
#define ICE_DESTR			"Ice:\t\tDestructor called\n"

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
