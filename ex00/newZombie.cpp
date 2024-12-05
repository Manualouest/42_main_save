/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:57:11 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/28 17:22:34 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*heapZombie;

	heapZombie = new (std::nothrow) Zombie;
	if (!heapZombie)
	{
		std::cout <<  "\033[31;1mHorde failed to be made, maybe try again 🤷‍\033[0m" << std::endl;
		return (NULL);
	}
	heapZombie->setName(name);
	return (heapZombie);
}