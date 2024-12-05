/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:57:14 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/28 17:06:15 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Mewen;
	Zombie	*Check;

	Mewen = newZombie("Mewen");
	Check = newZombie("");
	randomChump("Pierre");
	randomChump("");
	Mewen->announce();
	Check->announce();
	delete Mewen;
	delete Check;
	return (0);
}