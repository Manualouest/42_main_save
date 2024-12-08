/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:29:21 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/08 17:38:27 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(std::string("")), _hp(10), _energy(10), _dmg(0)
{
	PRINT GRN BOLD "ClapTrap Default constuctor called" CLR ENDL;
}

ClapTrap::ClapTrap(const ClapTrap &trap)
{
	PRINT  GRN BOLD "ClapTrap Copy constuctor called" CLR ENDL;
	*this = trap;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hp(10), _energy(10), _dmg(0)
{
	PRINT GRN BOLD "ClapTrap Name constuctor called" CLR ENDL;
}

ClapTrap	&ClapTrap::operator =(const ClapTrap &rhs)
{
	PRINT GRN BOLD "ClapTrap Copy assignement operator called" CLR ENDL;
	if (this != &rhs)
	{
		setName(rhs.getName());
		setHp(rhs.getHp());
		setEnergy(rhs.getEnergy());
		setDmg(rhs.getDmg());
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	PRINT RGB(200, 200, 0) BOLD "ClapTrap Destructor called" CLR ENDL;
}

void	ClapTrap::attack(const std::string &target)
{
	if (getEnergy() < 1)
		PRINT RED BOLD "ClapTrap " UNDL AND getName() AND RED BOLD " has no more energy! 🤦" CLR ENDL;
	else if (getHp() < 1)
		PRINT RED BOLD "ClapTrap " UNDL AND getName() AND RED BOLD " has no more hit points! 🫤" CLR ENDL;
	else
	{
		PRINT CYN BOLD "ClapTrap " UNDL AND getName() AND CYN BOLD " attacks and does " AND getDmg() AND " damage to " UNDL AND target AND CLR AND "😱" ENDL;
		setEnergy(getEnergy() - 1);
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (getHp() < 1)
		PRINT RED BOLD "ClapTrap " UNDL AND getName() AND RED BOLD " has no more hit points! 🫤" CLR ENDL;
	else if (amount >= getHp())
	{
		PRINT RED BOLD "ClapTrap " UNDL AND getName() AND RED BOLD " instantly died 🫤" CLR ENDL;
		setHp(0);
	}
	else
	{
		PRINT CYN BOLD "Oh no ClapTrap " UNDL AND getName() AND CYN BOLD " took damage 😭" CLR ENDL;
		setHp(getHp() - amount);
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (getEnergy() < 1)
		PRINT RED BOLD "ClapTrap " UNDL AND getName() AND RED BOLD " has no more energy! 🤦" CLR ENDL;
	else if (getHp() < 1)
		PRINT RED BOLD "ClapTrap " UNDL AND getName() AND RED BOLD " has no more hit points! 🫤" CLR ENDL;
	else
	{
		PRINT CYN BOLD "Yeepee ClapTrap " UNDL AND getName() AND CYN BOLD " is healing 😸" CLR ENDL;
		setHp(getHp() + amount);
		setEnergy(getEnergy() - 1);
	}
}

const std::string	&ClapTrap::getName() const
{
	return (_name);
}

void	ClapTrap::setName(const std::string &name)
{
	_name = name;
}

const unsigned int	&ClapTrap::getDmg() const
{
	return (_dmg);
}

void	ClapTrap::setDmg(const unsigned int &dmg)
{
	_dmg = dmg;
}

const unsigned int	&ClapTrap::getHp() const
{
	return (_hp);
}

void	ClapTrap::setHp(const unsigned int &hp)
{
	_hp = hp;
}

const unsigned int	&ClapTrap::getEnergy() const
{
	return (_energy);
}

void	ClapTrap::setEnergy(const unsigned int &energy)
{
	_energy = energy;
}
