/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:11:38 by vsanin            #+#    #+#             */
/*   Updated: 2025/04/22 10:52:13 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>
#include <sstream>

Brain::Brain()
{
	std::cout << B_DEF_CONSTR;
	std::ostringstream stream;

	for (int i = 0; i < 100; i++)
	{
		stream << i + 1;
		ideas[i] = "idea_" + stream.str();
		stream.str("");
		stream.clear();
	}
}

Brain::Brain(const Brain& ref)
{
	std::cout << B_COPY_CONSTR;
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = ref.ideas[i];
	}
}

Brain& Brain::operator=(const Brain& ref)
{
	std::cout << B_COPY_OP;
	if (this != &ref)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = ref.ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() { std::cout << B_DESTR; }

void Brain::showIdeas(void) const
{
	for (int i = 0; i < 3; i++)
		std::cout << ideas[i] << "\n";
	std::cout << "..." << "\n";	
	for (int i = 97; i < 100; i++)
		std::cout << ideas[i] << "\n";
}
