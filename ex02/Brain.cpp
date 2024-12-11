/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:52:49 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/11 15:17:25 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	PRINT GRN BOLD "Brain Constructor called" CLR ENDL;
}

Brain::Brain(const Brain &src)
{
	PRINT GRN BOLD "Brain Copy constructor called" CLR ENDL;
	*this = src;
}

Brain	&Brain::operator =(const Brain &rhs)
{
	PRINT GRN BOLD "Brain Copy assignement operator called" CLR ENDL;
	if (this != &rhs)
		for (int i = 0; i < 100; ++i)
			_ideas[i] = rhs._ideas[i];
	return (*this);
}

Brain::~Brain()
{
	PRINT RGB(200, 200, 0) BOLD "Brain Exploded" CLR ENDL;
}
