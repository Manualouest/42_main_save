/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:01:08 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/04 12:33:35 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string &name) : _weapon(NULL)
{
	if (name.empty())
	{
		std::cout	<< "\033[31;1mhey you forgot your name 🤦" << std::endl
					<< "You will then be named \033[4;1mSteve\033[0m" << std::endl;
		this->_name = "Steve";
	}
	else
		this->_name = name;
}

HumanB::~HumanB(void)
{
	std::cout << "\033[31;1mOh no " << this->_name << " was destroyed 😱\033[0m" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void	HumanB::attack(void) const
{
	if (!this->_weapon)
		std::cout	<< "\033[32;1m" << this->_name << " attacks with their hands since they have no weapon"
					<< std::endl << "\x1b[0m";
	else
		std::cout	<< "\033[32;1m" << this->_name << " attacks with their "
					<< this->_weapon->getType() << std::endl << "\x1b[0m";
}
