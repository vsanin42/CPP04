/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 17:37:01 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/18 11:42:17 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#define WC_DEF_CONSTR	"WrongCat:\tDefault constructor called\n"
#define WC_PARAM_CONSTR	"WrongCat:\tParametrized constructor called\n"
#define WC_COPY_CONSTR	"WrongCat:\tCopy constructor called\n"
#define WC_COPY_OP		"WrongCat:\tCopy assignment operator called\n"
#define WC_DESTR		"WrongCat:\tDestructor called\n"

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const std::string& newType);
		WrongCat(const WrongCat& ref);
		WrongCat& operator=(const WrongCat& ref);
		~WrongCat();

		void makeSound(void) const;
};

#endif
