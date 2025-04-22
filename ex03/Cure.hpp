/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:37:39 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/22 20:00:14 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#define CURE_DEF_CONSTR		"Cure:\tDefault constructor called\n"
#define CURE_PARAM_CONSTR	"Cure:\tParametrized constructor called\n"
#define CURE_COPY_CONSTR	"Cure:\tCopy constructor called\n"
#define CURE_COPY_OP		"Cure:\tCopy assignment operator called\n"
#define CURE_DESTR			"Cure:\tDestructor called\n"

#include "AMateria.hpp"
#include <string>

class Cure : public AMateria
{
	public:
		Cure();
		Cure(std::string const& type);
		Cure(const Cure& ref);
		Cure& operator=(const Cure& ref);
		~Cure();
		
		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
