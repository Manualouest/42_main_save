/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:22:34 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/28 12:34:42 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure()
{
	_type = "cure";
}

Cure::Cure(const Cure &src)
{
	*this = src;
}

Cure	&Cure::operator =(const Cure &rhs)
{
	if (this != &rhs)
		_type = rhs.getType();
	return (*this);
}

Cure::~Cure()
{
}

std::string const	&Cure::getType() const
{
	return (_type);
}

AMateria	*Cure::clone() const
{
	AMateria	*CureClone = new Cure();
	return (CureClone);
}

void	Cure::use(ICharacter &target)
{
	PRINT CYN BOLD "🧙 Heals " AND target.getName() AND "'s wounds ✨" CLR ENDL;
}