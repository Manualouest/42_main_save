/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:52:42 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/08 17:45:48 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	PRINT GRN BOLD "ScavTrap Default constructor called" CLR ENDL;
	setName("");
	setHp(SCAV_HP);
	setEnergy(SCAV_EP);
	setDmg(SCAV_DMG);
	setGuard(false);
}

ScavTrap::ScavTrap(const ScavTrap &trap)
{
	PRINT GRN BOLD "ScavTrap Copy constructor called" CLR ENDL;
	*this = trap;
}

ScavTrap::ScavTrap(const std::string &name)
{
	PRINT GRN BOLD "ScavTrap Name constructor called" CLR ENDL;
	setName(name);
	setHp(SCAV_HP);
	setEnergy(SCAV_EP);
	setDmg(SCAV_DMG);
	setGuard(false);
}

ScavTrap	&ScavTrap::operator =(const ScavTrap &rhs)
{
	PRINT GRN BOLD "ScavTrap Copy assignement operator called" CLR ENDL;
	if (this != &rhs)
	{
		setName(rhs.getName());
		setHp(rhs.getHp());
		setEnergy(rhs.getEnergy());
		setDmg(rhs.getDmg());
		setGuard(rhs.getGuard());
	}
	return (*this);
}

ScavTrap::~ScavTrap()
{
	PRINT RGB(200, 200, 0) BOLD "ScavTrap Destructor called" CLR ENDL;
}

void	ScavTrap::attack(const std::string &target)
{
	if (getEnergy() < 1)
		PRINT RED BOLD "ScavTrap " UNDL AND getName() AND RED BOLD " has no more energy! 🤦" CLR ENDL;
	else if (getHp() < 1)
		PRINT RED BOLD "ScavTrap " UNDL AND getName() AND RED BOLD " has no more hit points! 🫤" CLR ENDL;
	else
	{
		PRINT CYN BOLD "ScavTrap " UNDL AND getName() AND CYN BOLD " attacks and does " AND getDmg() AND " to " UNDL AND target AND CLR AND "😱" ENDL;
		setEnergy(getEnergy() - 1);
	}
}

void	ScavTrap::guardGate()
{
	if (getEnergy() < 1)
		PRINT RED BOLD "ScavTrap " UNDL AND getName() AND RED BOLD " has no more energy! 🤦" CLR ENDL;
	else if (getHp() < 1)
		PRINT RED BOLD "ScavTrap " UNDL AND getName() AND RED BOLD " has no more hit points! 🫤" CLR ENDL;
	else if (getGuard())
	{
		setGuard(false);
		PRINT CYN BOLD "ScavTrap " UNDL AND getName() AND CYN BOLD " is no longer in Gate keeper mode 😯" CLR ENDL;
	}
	else
	{
		setGuard(true);
		PRINT CYN BOLD "ScavTrap " UNDL AND getName() AND CYN BOLD " is now in Gate keeper mode 😯" CLR ENDL;
	}
}

void	ScavTrap::setGuard(const bool &status)
{
	_guardStatus = status;
}

const bool &ScavTrap::getGuard() const
{
	return (_guardStatus);
}
