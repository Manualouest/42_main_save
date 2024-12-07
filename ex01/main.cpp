/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 17:59:29 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/07 18:39:42 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <spellbook.hpp>

int	main()
{
	ClapTrap	trapA;
	ClapTrap	trapB("trapB");
	ClapTrap	trapC = trapA;
	trapA.setName("trapA");
	trapA.setDmg(9);
	trapA.setEnergy(2);
	trapC.setName("trapC");
	trapC.setDmg(10);

	NEWL;
	PRINT BOLD AND trapA.getName() AND " tries to attack " AND trapB.getName() ENDL;
	trapA.attack(trapB.getName());
	trapB.takeDamage(trapA.getDmg());
	PRINT trapA.getName() AND " now has " AND trapA.getEnergy() AND " energy" ENDL;
	PRINT trapB.getName() AND " now has " AND trapB.getHp() AND " hit point" ENDL;
	
	NEWL;
	PRINT BOLD AND trapB.getName() AND " tries to heal" ENDL;
	trapB.beRepaired(8);
	PRINT trapB.getName() AND " now has " AND trapB.getEnergy() AND " energy" ENDL;
	PRINT trapB.getName() AND " now has " AND trapB.getHp() AND " hit point" ENDL;
	
	NEWL;
	PRINT BOLD AND trapA.getName() AND " tries to attack " AND trapB.getName() ENDL;
	trapA.attack(trapB.getName());
	trapB.takeDamage(trapA.getDmg());
	PRINT trapA.getName() AND " now has " AND trapA.getEnergy() AND " energy" ENDL;
	PRINT trapB.getName() AND " now has " AND trapB.getHp() AND " hit point" ENDL;
	
	NEWL;
	PRINT BOLD AND trapB.getName() AND " tries to heal" ENDL;
	trapB.beRepaired(8);
	PRINT trapB.getName() AND " now has " AND trapB.getEnergy() AND " energy" ENDL;
	PRINT trapB.getName() AND " now has " AND trapB.getHp() AND " hit point" ENDL;

	NEWL;
	PRINT BOLD AND trapA.getName() AND " tries to attack " AND trapC.getName() ENDL;
	trapA.attack(trapC.getName());

	NEWL;
	PRINT BOLD AND trapC.getName() AND " tries to attack " AND trapA.getName() ENDL;
	trapC.attack(trapA.getName());
	trapA.takeDamage(trapC.getDmg());
	PRINT trapC.getName() AND " now has " AND trapC.getEnergy() AND " energy" ENDL;
	PRINT trapA.getName() AND " now has " AND trapA.getHp() AND " hit point" AND CLR ENDL;
	NEWL;
}
