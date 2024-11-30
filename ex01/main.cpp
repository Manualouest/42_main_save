/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:57:14 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/28 17:21:23 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Horde;
	int		N;

	N = 1;
	Horde = zombieHorde(N, "Mewen");
	for (int i = 0; i < N; ++i)
	{
		std::cout << "\033[39;1;4m" << i << "\033[0m ";
		Horde[i].announce();
	}
	delete [] Horde;
	N = 0;
	Horde = zombieHorde(N, "Pierre");
	for (int i = 0; i < N; ++i)
	{
		std::cout << "\033[39;1;4m" << i << "\033[0m ";
		Horde[i].announce();
	}
	delete [] Horde;
	N = 5;
	Horde = zombieHorde(N, "");
	for (int i = 0; i < N; ++i)
	{
		std::cout << "\033[39;1;4m" << i << "\033[0m ";
		Horde[i].announce();
	}
	delete [] Horde;
	N = 2147483647;
	Horde = zombieHorde(N, "Jean");
	// for (int i = 0; i < N; ++i) // creates segfault due to protection
	// {
	// 	std::cout << "\033[39;1;4m" << i << "\033[0m ";
	// 	Horde[i].announce();
	// }
	delete [] Horde;
	return (0);
}