/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:29:21 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/07 18:37:11 by mbirou           ###   ########.fr       */
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
		this->_name = rhs.getName();
		this->_hp = rhs.getHp();
		this->_energy = rhs.getEnergy();
		this->_dmg = rhs.getDmg();
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	PRINT RGB(200, 200, 0) BOLD "ClapTrap Destructor called" CLR ENDL;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->getEnergy() < 1)
		PRINT RED BOLD UNDL AND this->getName() AND RED BOLD " has no more energy! 🤦" CLR ENDL;
	else if (this->getHp() < 1)
		PRINT RED BOLD UNDL AND this->getName() AND RED BOLD " has no more hit points! 🫤" CLR ENDL;
	else
	{
		PRINT CYN BOLD UNDL AND this->getName() AND CYN BOLD " attacks and does " AND this->getDmg() AND " to " UNDL AND target AND CLR AND "😱" ENDL;
		this->setEnergy(this->getEnergy() - 1);
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->getHp() < 1)
		PRINT RED BOLD UNDL AND this->getName() AND RED BOLD " has no more hit points! 🫤" CLR ENDL;
	else if (amount >= this->getHp())
	{
		PRINT RED BOLD UNDL AND this->getName() AND RED BOLD " instantly died 🫤" CLR ENDL;
		this->setHp(0);
	}
	else
	{
		PRINT CYN BOLD "Oh no " UNDL AND this->getName() AND CYN BOLD " took damage 😭" CLR ENDL;
		this->setHp(this->getHp() - amount);
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergy() < 1)
		PRINT RED BOLD UNDL AND this->getName() AND RED BOLD " has no more energy! 🤦" CLR ENDL;
	else if (this->getHp() < 1)
		PRINT RED BOLD UNDL AND this->getName() AND RED BOLD " has no more hit points! 🫤" CLR ENDL;
	else
	{
		PRINT CYN BOLD "Yeepee " UNDL AND this->getName() AND CYN BOLD " is healing 😸" CLR ENDL;
		this->setHp(this->getHp() + amount);
		this->setEnergy(this->getEnergy() - 1);
	}
}

const std::string	&ClapTrap::getName() const
{
	return (this->_name);
}

void	ClapTrap::setName(const std::string &name)
{
	this->_name = name;
}

const unsigned int	&ClapTrap::getDmg() const
{
	return (this->_dmg);
}

void	ClapTrap::setDmg(const unsigned int &dmg)
{
	this->_dmg = dmg;
}

const unsigned int	&ClapTrap::getHp() const
{
	return (this->_hp);
}

void	ClapTrap::setHp(const unsigned int &hp)
{
	this->_hp = hp;
}

const unsigned int	&ClapTrap::getEnergy() const
{
	return (this->_energy);
}

void	ClapTrap::setEnergy(const unsigned int &energy)
{
	this->_energy = energy;
}
