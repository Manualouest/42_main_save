/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:32:33 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/08 17:48:21 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	PRINT GRN BOLD "DiamondTrap Default constructor called" CLR ENDL;
	setName("_clap_name");
	_name = "";
	setHp(DIAMOND_HP);
	setEnergy(DIAMOND_EP);
	setDmg(DIAMOND_DMG);
}

DiamondTrap::DiamondTrap(const DiamondTrap &trap)
{
	PRINT GRN BOLD "DiamondTrap Copy constructor called" CLR ENDL;
	*this = trap;
}

DiamondTrap::DiamondTrap(const std::string &name)
{
	PRINT GRN BOLD "DiamondTrap Name constructor called" CLR ENDL;
	std::string clapName = name;
	setName(clapName.append(std::string("_clap_name")));
	_name = name;
	setHp(DIAMOND_HP);
	setEnergy(DIAMOND_EP);
	setDmg(DIAMOND_DMG);
}

DiamondTrap	&DiamondTrap::operator =(const DiamondTrap &rhs)
{
	PRINT GRN BOLD "DiamondTrap Copy assignement operator called" CLR ENDL;
	if (this != &rhs)
	{
		setName(rhs.getName());
		_name = rhs._name;
		setHp(rhs.getHp());
		setEnergy(rhs.getEnergy());
		setDmg(rhs.getDmg());
	}
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	PRINT RGB(200, 200, 0) BOLD "DiamondTrap Destructor called" CLR ENDL;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI()
{
	PRINT CYN BOLD "DiamondTrap name:" TAB UNDL AND _name AND CLR ENDL;
	PRINT CYN BOLD "ClapTrap name:" TAB TAB UNDL AND getName() AND CLR ENDL;
}
