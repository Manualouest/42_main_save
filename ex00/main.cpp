/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:57:14 by mbirou            #+#    #+#             */
/*   Updated: 2024/11/28 12:42:29 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Mewen;

	Mewen = newZombie("Mewen");
	randomChump("Pierre");
	Mewen->announce();
	delete Mewen;
	return (0);
}