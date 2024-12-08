/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:59:29 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/08 17:49:20 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <spellBook.hpp>

int	main()
{
	NEWL;
	PRINT RGB(255, 165, 0) BOLD "══════════════════════════════════════════════" CLR ENDL;
	{
		NEWL;
		PRINT BOLD UNDL "ScavTrap" CLR ENDL;
		ScavTrap	StrapA("ScavTrap");

		NEWL;
		PRINT BOLD UNDL "Default" CLR BOLD ":" ENDL;
		PRINT TAB "Name:" TAB TAB AND StrapA.getName() ENDL;
		PRINT TAB "Hit point:" TAB AND StrapA.getHp() ENDL;
		PRINT TAB "Energy:" TAB TAB AND StrapA.getEnergy() ENDL;
		PRINT TAB "Damage:" TAB TAB AND StrapA.getDmg() ENDL;
	}
	{
		NEWL;
		PRINT BOLD UNDL "FragTrap" CLR ENDL;
		FragTrap	FtrapA("FragTrap");

		NEWL;
		PRINT BOLD UNDL "Default" CLR BOLD ":" ENDL;
		PRINT TAB "Name:" TAB TAB AND FtrapA.getName() ENDL;
		PRINT TAB "Hit point:" TAB AND FtrapA.getHp() ENDL;
		PRINT TAB "Energy:" TAB TAB AND FtrapA.getEnergy() ENDL;
		PRINT TAB "Damage:" TAB TAB AND FtrapA.getDmg() ENDL;
	}
	NEWL;
	PRINT RGB(255, 165, 0) BOLD "══════════════════════════════════════════════" CLR ENDL;
	{
		NEWL;
		PRINT BOLD UNDL "DiamondTrap" CLR ENDL;
		DiamondTrap	DtrapA("DiamondTrap");

		NEWL;
		PRINT BOLD UNDL "Default" CLR BOLD ":" ENDL;
		PRINT TAB "Name:" TAB TAB AND DtrapA.getName() ENDL;
		PRINT TAB "Hit point:" TAB AND DtrapA.getHp() ENDL;
		PRINT TAB "Energy:" TAB TAB AND DtrapA.getEnergy() ENDL;
		PRINT TAB "Damage:" TAB TAB AND DtrapA.getDmg() ENDL;

		NEWL;
		DtrapA.attack("StrapA");
		DtrapA.highFivesGuys();
		DtrapA.guardGate();
		NEWL;
		DtrapA.whoAmI();
		NEWL;
	}
	NEWL;
	PRINT RGB(255, 165, 0) BOLD "══════════════════════════════════════════════" CLR ENDL;
}
