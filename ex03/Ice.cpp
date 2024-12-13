/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:19:10 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/13 14:24:12 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	_type = "ice";
}

Ice::Ice(const Ice &src)
{
	*this = src;
}

Ice	&Ice::operator =(const Ice &rhs)
{
	if (this != &rhs)
		_type = rhs.getType();
}

Ice::Ice(std::string const &type)
{
}

Ice::~Ice()
{
}

std::string const	&Ice::getType() const
{
	return (_type);
}

AMateria	*Ice::clone() const
{
	AMateria	*IceClone = new Ice();
	return (IceClone);
}

void	Ice::use(ICharacter &target)
{
	PRINT CYN BOLD "🧙 Shoots an ice bold at " AND target.getName() AND " 🥶" CLR ENDL;
}