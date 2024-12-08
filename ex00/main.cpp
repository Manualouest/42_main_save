/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:40:04 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/08 15:59:47 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <spellBook.hpp>

int	main()
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
