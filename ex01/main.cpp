/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:59:29 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/08 16:00:58 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <spellBook.hpp>

int	main()
{
	NEWL;
	PRINT RGB(255, 165, 0) BOLD "══════════════════════════════════════════════" CLR ENDL;
	{
		PRINT BOLD UNDL "ClapTrap" CLR ENDL;
		ClapTrap	CtrapA;
		ClapTrap	CtrapB("CtrapB");
		ClapTrap	CtrapC = CtrapA;

		NEWL;
		PRINT BOLD UNDL "Default" CLR BOLD ":" ENDL;
		PRINT TAB "Name:" TAB TAB AND CtrapB.getName() ENDL;
		PRINT TAB "Hit point:" TAB AND CtrapB.getHp() ENDL;
		PRINT TAB "Energy:" TAB TAB AND CtrapB.getEnergy() ENDL;
		PRINT TAB "Damage:" TAB TAB AND CtrapB.getDmg() ENDL;

		NEWL;
		CtrapA.setName("CtrapA");
		CtrapA.setDmg(9);
		CtrapA.setEnergy(2);
		CtrapC.setName("CtrapC");
		CtrapC.setDmg(10);

		NEWL;
		PRINT BOLD AND CtrapA.getName() AND " tries to attack " AND CtrapB.getName() ENDL;
		CtrapA.attack(CtrapB.getName());
		CtrapB.takeDamage(CtrapA.getDmg());
		PRINT CtrapA.getName() AND " now has " AND CtrapA.getEnergy() AND " energy" ENDL;
		PRINT CtrapB.getName() AND " now has " AND CtrapB.getHp() AND " hit point" ENDL;
		
		NEWL;
		PRINT BOLD AND CtrapB.getName() AND " tries to heal" ENDL;
		CtrapB.beRepaired(8);
		PRINT CtrapB.getName() AND " now has " AND CtrapB.getEnergy() AND " energy" ENDL;
		PRINT CtrapB.getName() AND " now has " AND CtrapB.getHp() AND " hit point" ENDL;
		
		NEWL;
		PRINT BOLD AND CtrapA.getName() AND " tries to attack " AND CtrapB.getName() ENDL;
		CtrapA.attack(CtrapB.getName());
		CtrapB.takeDamage(CtrapA.getDmg());
		PRINT CtrapA.getName() AND " now has " AND CtrapA.getEnergy() AND " energy" ENDL;
		PRINT CtrapB.getName() AND " now has " AND CtrapB.getHp() AND " hit point" ENDL;
		
		NEWL;
		PRINT BOLD AND CtrapB.getName() AND " tries to heal" ENDL;
		CtrapB.beRepaired(8);
		PRINT CtrapB.getName() AND " now has " AND CtrapB.getEnergy() AND " energy" ENDL;
		PRINT CtrapB.getName() AND " now has " AND CtrapB.getHp() AND " hit point" ENDL;

		NEWL;
		PRINT BOLD AND CtrapA.getName() AND " tries to attack " AND CtrapC.getName() ENDL;
		CtrapA.attack(CtrapC.getName());

		NEWL;
		PRINT BOLD AND CtrapC.getName() AND " tries to attack " AND CtrapA.getName() ENDL;
		CtrapC.attack(CtrapA.getName());
		CtrapA.takeDamage(CtrapC.getDmg());
		PRINT CtrapC.getName() AND " now has " AND CtrapC.getEnergy() AND " energy" ENDL;
		PRINT CtrapA.getName() AND " now has " AND CtrapA.getHp() AND " hit point" AND CLR ENDL;
		NEWL;
	}
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
}
