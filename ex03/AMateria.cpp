/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:42:38 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/12 15:50:37 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	_type = "";
}


AMateria::AMateria(const AMateria &src)
{
	*this = src;
}

AMateria	&AMateria::operator =(const AMateria &rhs)
{
	if (this != &rhs)
		_type = rhs.getType();
}

AMateria::AMateria(std::string const &type)
{
	_type = type;
}

AMateria::~AMateria()
{
}

std::string const	&AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter &target)
{
	PRINT CYN BOLD "Shoots abstaction at " AND target.getName() AND CLR ENDL;
}
