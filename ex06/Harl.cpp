/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:56:42 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/04 11:44:33 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	std::cout << "\033[32;1mHarl created\033[0m 🤖" << std::endl;
}

Harl::~Harl(void)
{
	std::cout << "\033[32;1mHarl destroyed\033[0m 😿" << std::endl;
}

void	Harl::complain(const std::string &level)
{
	int	i;
	for (i = 0; i < 4 && this->_levels[i] != level; ++i)
		;
	switch (i)
	{
		case 0:
			this->debug();
			HARL_FALLTHROUGH;
		case 1:
			this->info();
			HARL_FALLTHROUGH;
		case 2:
			this->warning();
			HARL_FALLTHROUGH;
		case 3:
			this->error();
			break ;
		default:
			std::cout << std::endl << "\033[31;1m\"\033[31;4;1m" << level << "\033[0m\033[31;1m\" Isn't a level Harl can understand 🤖\033[0m" << std::endl;
	}
}

void	Harl::debug(void) const
{
	std::cout	<< std::endl << "\033[31;1;4m[DEBUG]\033[0m" << std::endl
				<< "\033[31;1m🧙 The Shadow Wizard Money Gang" << std::endl
				<< "\twants to cast High Mana Cost Insanely Destructive Doomsday-threat-level Spells 🤯\033[0m" << std::endl;
}

void	Harl::info(void) const
{
	std::cout	<< std::endl << "\033[31;1;4m[INFO]\033[0m" << std::endl
				<< "\033[31;1m🧙 The Shadow Wizard Money Gang loves casting spells" << std::endl
				<< "\tand has earned quite a lot of mana and is ready to cast some spells 😎\033[0m" << std::endl;
}

void	Harl::warning(void) const
{
	std::cout	<< std::endl << "\033[31;1;4m[WARNING]\033[0m" << std::endl
				<< "\033[31;1m🧙 The Shadow Wizard Money Gang" << std::endl
				<< "\tdoesn't currently have that much mana 😢\033[0m" << std::endl;
}
void	Harl::error(void) const
{
	std::cout	<< std::endl << "\033[31;1;4m[ERROR]\033[0m" << std::endl
				<< "\033[31;1m🧙 The Shadow Wizard Money Gang" << std::endl
				<< "\tblew themselves up by failing their spells 😱\033[0m" << std::endl;
}
