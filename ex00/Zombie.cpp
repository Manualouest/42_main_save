/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:56:50 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/04 12:32:32 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "\033[31;1mZombie created 😱\033[0m" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "\033[31;1m" << this->_name << " destroyed 🥳\033[0m" << std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << "\033[31;1m🧟 " << this->_name << ": \033[0m\033[31mBraiiiiiiinnnzzzZ... 😋🧠\033[0m" << std::endl;
}

void	Zombie::setName(const std::string &name)
{
	if (name.empty())
	{
		std::cout << "\033[31;1mYou forgot to name your zombie dummy so it will be named Crazy Dave 🌮" << std::endl;
		this->_name = "Crazy Dave";
	}
	else
		this->_name = name;
}
