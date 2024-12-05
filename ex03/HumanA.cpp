/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 18:58:43 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/04 12:33:45 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(const std::string &name, Weapon &weapon) : _weapon(weapon)
{
	if (name.empty())
	{
		std::cout	<< "\033[31;1mhey you forgot your name 🤦" << std::endl
					<< "You will then be named \033[4;1mJhon\033[0m" << std::endl;
		this->_name = "Jhon";
	}
	else
		this->_name = name;
}

HumanA::~HumanA(void)
{
	std::cout << "\033[31;1mOh no " << this->_name << " was destroyed 😱\033[0m" << std::endl;
}

void	HumanA::attack(void) const
{
	std::cout	<< "\033[32;1m" << this->_name << " attacks with their "
				<< this->_weapon.getType() << "\x1b[0m 😼" << std::endl;
}