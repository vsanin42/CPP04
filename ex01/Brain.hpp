/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:06:24 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/22 10:49:51 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#define B_DEF_CONSTR	"Brain:\tDefault constructor called\n"
#define B_COPY_CONSTR	"Brain:\tCopy constructor called\n"
#define B_COPY_OP		"Brain:\tCopy assignment operator called\n"
#define B_DESTR			"Brain:\tDestructor called\n"

#include <string>

class Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain();
		Brain(const Brain& ref);
		Brain& operator=(const Brain& ref);
		~Brain();

		void showIdeas(void) const;
};

#endif
