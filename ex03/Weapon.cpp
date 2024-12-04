/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:01:16 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/04 12:26:40 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string &type)
{
	this->setType(type);
}

Weapon::~Weapon(void)
{
	std::cout << "\033[31;1mWeapon was lost forever \033[0m😿" << std::endl;
}

void	Weapon::setType(const std::string &type)
{
	if (type.empty())
	{
		std::cout << "\033[31;1mdamn at least use your hands \033[0m🤦" << std::endl;
		this->_type = "hands";
	}
	else
		this->_type = type;
}

const std::string	&Weapon::getType(void) const
{
	return (this->_type);
}
