/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:12:46 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/23 17:15:09 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#define SRC_DEF_CONSTR		"MateriaSource:\tDefault constructor called\n"
#define SRC_PARAM_CONSTR	"MateriaSource:\tParametrized constructor called\n"
#define SRC_COPY_CONSTR		"MateriaSource:\tCopy constructor called\n"
#define SRC_COPY_OP			"MateriaSource:\tCopy assignment operator called\n"
#define SRC_DESTR			"MateriaSource:\tDestructor called\n\n"

#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include <string>

class MateriaSource : public IMateriaSource
{
	private:
		AMateria* memory[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& ref);
		MateriaSource& operator=(const MateriaSource& ref);
		~MateriaSource();
		
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const& type);
};

#endif
