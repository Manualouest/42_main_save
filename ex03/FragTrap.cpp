/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:03:26 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/08 17:45:03 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	PRINT GRN BOLD "FragTrap Default constructor called" CLR ENDL;
	setName("");
	setHp(FRAG_HP);
	setEnergy(FRAG_EP);
	setDmg(FRAG_DMG);
}

FragTrap::FragTrap(const FragTrap &trap)
{
	PRINT GRN BOLD "FragTrap Copy constructor called" CLR ENDL;
	*this = trap;
}

FragTrap::FragTrap(const std::string &name)
{
	PRINT GRN BOLD "FragTrap Name constructor called" CLR ENDL;
	setName(name);
	setHp(FRAG_HP);
	setEnergy(FRAG_EP);
	setDmg(FRAG_DMG);
}

FragTrap	&FragTrap::operator =(const FragTrap &rhs)
{
	PRINT GRN BOLD "FragTrap Copy assignement operator called" CLR ENDL;
	if (this != &rhs)
	{
		setName(rhs.getName());
		setHp(rhs.getHp());
		setEnergy(rhs.getEnergy());
		setDmg(rhs.getDmg());
	}
	return (*this);
}

FragTrap::~FragTrap()
{
	PRINT RGB(200, 200, 0) BOLD "FragTrap Destructor called" CLR ENDL;
}

void	FragTrap::highFivesGuys()
{
	if (getEnergy() < 1)
		PRINT RED BOLD "FragTrap " UNDL AND getName() AND RED BOLD " has no more energy! 🤦" CLR ENDL;
	else if (getHp() < 1)
		PRINT RED BOLD "FragTrap " UNDL AND getName() AND RED BOLD " has no more hit points! 🫤" CLR ENDL;
	else
		PRINT CYN BOLD "Hey guys wanna high five? 🫸" CLR ENDL;
}
