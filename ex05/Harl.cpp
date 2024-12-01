/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:56:42 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/01 17:57:14 by mbirou           ###   ########.fr       */
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

void	Harl::complain(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void		(Harl::*complains[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	for (int i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
		{
			(this->*complains[i])();
			return ;
		}
	}
	std::cout << "\033[31;1m\"\033[31;4;1m" << level << "\033[0m\033[31;1m\" Isn't a level Harl can understand 🤖\033[0m" << std::endl;
}

void	Harl::debug(void)
{
	std::cout	<< "\033[31;1m🧙 The Shadow Wizard Money Gang" << std::endl
				<< "\twants to cast High Mana Cost Insanely Destructive Doomsday-threat-level Spells 🤯\033[0m" << std::endl;
}

void	Harl::info(void)
{
	std::cout	<< "\033[31;1m🧙 The Shadow Wizard Money Gang" << std::endl
				<< "\thas earned quite a lot of mana and is ready to cast some spells 😎\033[0m" << std::endl;
}

void	Harl::warning(void)
{
	std::cout	<< "\033[31;1m🧙 The Shadow Wizard Money Gang" << std::endl
				<< "\tdoesn't currently have that much mana 😢\033[0m" << std::endl;
}
void	Harl::error(void)
{
	std::cout	<< "\033[31;1m🧙 The Shadow Wizard Money Gang" << std::endl
				<< "\tblew themselves up by failing their spells 😱\033[0m" << std::endl;
}
