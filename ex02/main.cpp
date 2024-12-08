/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:59:29 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/08 16:02:13 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <spellBook.hpp>

int	main()
{
	NEWL;
	PRINT RGB(255, 165, 0) BOLD "══════════════════════════════════════════════" CLR ENDL;
	{
		NEWL;
		PRINT BOLD UNDL "ScavTrap" CLR ENDL;
		ScavTrap	StrapA;
		ScavTrap	StrapB("StrapB");
		ScavTrap	StrapC = StrapA;

		NEWL;
		PRINT BOLD UNDL "Default" CLR BOLD ":" ENDL;
		PRINT TAB "Name:" TAB TAB AND StrapB.getName() ENDL;
		PRINT TAB "Hit point:" TAB AND StrapB.getHp() ENDL;
		PRINT TAB "Energy:" TAB TAB AND StrapB.getEnergy() ENDL;
		PRINT TAB "Damage:" TAB TAB AND StrapB.getDmg() ENDL;

		StrapA.setName("StrapA");
		StrapA.setHp(10);
		StrapA.setDmg(9);
		StrapB.setEnergy(1);
		StrapC.setName("StrapC");

		NEWL;
		PRINT BOLD AND StrapA.getName() AND " tries to attack " AND StrapB.getName() ENDL;
		StrapA.attack(StrapB.getName());
		StrapB.takeDamage(StrapA.getDmg());
		PRINT StrapA.getName() AND " now has " AND StrapA.getEnergy() AND " energy" ENDL;
		PRINT StrapB.getName() AND " now has " AND StrapB.getHp() AND " hit point" ENDL;
		
		NEWL;
		PRINT BOLD AND StrapB.getName() AND " tries to heal" ENDL;
		StrapB.beRepaired(8);
		PRINT StrapB.getName() AND " now has " AND StrapB.getEnergy() AND " energy" ENDL;
		PRINT StrapB.getName() AND " now has " AND StrapB.getHp() AND " hit point" ENDL;
		
		NEWL;
		PRINT BOLD AND StrapA.getName() AND " tries to attack " AND StrapB.getName() ENDL;
		StrapA.attack(StrapB.getName());
		StrapB.takeDamage(StrapA.getDmg());
		PRINT StrapA.getName() AND " now has " AND StrapA.getEnergy() AND " energy" ENDL;
		PRINT StrapB.getName() AND " now has " AND StrapB.getHp() AND " hit point" ENDL;
		
		NEWL;
		PRINT BOLD AND StrapB.getName() AND " tries to heal" ENDL;
		StrapB.beRepaired(8);
		PRINT StrapB.getName() AND " now has " AND StrapB.getEnergy() AND " energy" ENDL;
		PRINT StrapB.getName() AND " now has " AND StrapB.getHp() AND " hit point" ENDL;

		NEWL;
		PRINT BOLD AND StrapA.getName() AND " tries to attack " AND StrapC.getName() ENDL;
		StrapA.attack(StrapC.getName());

		NEWL;
		PRINT BOLD AND StrapC.getName() AND " tries to attack " AND StrapA.getName() ENDL;
		StrapC.attack(StrapA.getName());
		StrapA.takeDamage(StrapC.getDmg());
		PRINT StrapC.getName() AND " now has " AND StrapC.getEnergy() AND " energy" ENDL;
		PRINT StrapA.getName() AND " now has " AND StrapA.getHp() AND " hit point" AND CLR ENDL;
		
		NEWL;
		StrapA.guardGate();
		StrapB.guardGate();
		StrapC.guardGate();
		StrapC.guardGate();
		NEWL;
	}
	NEWL;
	PRINT RGB(255, 165, 0) BOLD "══════════════════════════════════════════════" CLR ENDL;
	{
		NEWL;
		PRINT BOLD UNDL "FragTrap" CLR ENDL;
		FragTrap	FtrapA;
		FragTrap	FtrapB("FtrapB");
		FragTrap	FtrapC = FtrapA;

		NEWL;
		PRINT BOLD UNDL "Default" CLR BOLD ":" ENDL;
		PRINT TAB "Name:" TAB TAB AND FtrapB.getName() ENDL;
		PRINT TAB "Hit point:" TAB AND FtrapB.getHp() ENDL;
		PRINT TAB "Energy:" TAB TAB AND FtrapB.getEnergy() ENDL;
		PRINT TAB "Damage:" TAB TAB AND FtrapB.getDmg() ENDL;

		FtrapA.setName("FtrapA");
		FtrapA.setHp(10);
		FtrapA.setDmg(9);
		FtrapB.setEnergy(1);
		FtrapC.setName("FtrapC");

		NEWL;
		PRINT BOLD AND FtrapA.getName() AND " tries to attack " AND FtrapB.getName() ENDL;
		FtrapA.attack(FtrapB.getName());
		FtrapB.takeDamage(FtrapA.getDmg());
		PRINT FtrapA.getName() AND " now has " AND FtrapA.getEnergy() AND " energy" ENDL;
		PRINT FtrapB.getName() AND " now has " AND FtrapB.getHp() AND " hit point" ENDL;
		
		NEWL;
		PRINT BOLD AND FtrapB.getName() AND " tries to heal" ENDL;
		FtrapB.beRepaired(8);
		PRINT FtrapB.getName() AND " now has " AND FtrapB.getEnergy() AND " energy" ENDL;
		PRINT FtrapB.getName() AND " now has " AND FtrapB.getHp() AND " hit point" ENDL;
		
		NEWL;
		PRINT BOLD AND FtrapA.getName() AND " tries to attack " AND FtrapB.getName() ENDL;
		FtrapA.attack(FtrapB.getName());
		FtrapB.takeDamage(FtrapA.getDmg());
		PRINT FtrapA.getName() AND " now has " AND FtrapA.getEnergy() AND " energy" ENDL;
		PRINT FtrapB.getName() AND " now has " AND FtrapB.getHp() AND " hit point" ENDL;
		
		NEWL;
		PRINT BOLD AND FtrapB.getName() AND " tries to heal" ENDL;
		FtrapB.beRepaired(8);
		PRINT FtrapB.getName() AND " now has " AND FtrapB.getEnergy() AND " energy" ENDL;
		PRINT FtrapB.getName() AND " now has " AND FtrapB.getHp() AND " hit point" ENDL;

		NEWL;
		PRINT BOLD AND FtrapA.getName() AND " tries to attack " AND FtrapC.getName() ENDL;
		FtrapA.attack(FtrapC.getName());

		NEWL;
		PRINT BOLD AND FtrapC.getName() AND " tries to attack " AND FtrapA.getName() ENDL;
		FtrapC.attack(FtrapA.getName());
		FtrapA.takeDamage(FtrapC.getDmg());
		PRINT FtrapC.getName() AND " now has " AND FtrapC.getEnergy() AND " energy" ENDL;
		PRINT FtrapA.getName() AND " now has " AND FtrapA.getHp() AND " hit point" AND CLR ENDL;
		
		NEWL;
		FtrapA.highFivesGuys();
		FtrapB.highFivesGuys();
		FtrapC.highFivesGuys();
		FtrapC.highFivesGuys();
		NEWL;
	}
	NEWL;
	PRINT RGB(255, 165, 0) BOLD "══════════════════════════════════════════════" CLR ENDL;
}
