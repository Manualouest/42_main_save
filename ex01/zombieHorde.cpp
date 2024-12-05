/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:03:12 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/28 17:19:55 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*horde;

	if (N < 1)
	{
		std::cout << "\033[31;1mWhy are you trying to make 0 zombies 🤨???\033[0m" << std::endl;
		return (NULL);
	}
	if (N == 1)
		std::cout << "\033[31;1mPlease seek the definition of \033[31;1;4mHORDE\033[0m\033[31;1m, but alright... 🤦‍\033[0m" << std::endl;
	horde = new (std::nothrow) Zombie[N];
	if (!horde)
	{
		std::cout <<  "\033[31;1mHorde failed to be made, maybe try again 🤷‍\033[0m" << std::endl;
		return (NULL);
	}
	for (int i = 0; i < N; ++i)
		horde[i].setName(name);
	return (horde);
}
