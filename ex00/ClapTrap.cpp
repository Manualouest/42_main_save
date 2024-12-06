/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 17:29:21 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/06 19:50:12 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(std::string("")), _hp(10), _energy(10), _dmg(0)
{
	std::cout << "\033[32;1mDefault constuctor called\033[0m" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &trap)
{
	std::cout << "\033[32;1mCopy constuctor called\033[0m" << std::endl;
	*this = trap;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hp(10), _energy(10), _dmg(0)
{
	std::cout << "\033[32;1mName constuctor called\033[0m" << std::endl;
}

ClapTrap	&ClapTrap::operator =(const ClapTrap &rhs)
{
	std::cout << "\033[32;1mCopy assignement operator called\033[0m" << std::endl;
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
	std::cout << "\033[1;38;2;200;200;0mDestructor called\033[0m" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
	if (this->getEnergy() < 1)
		std::cout << RED BOLD UNDL << this->getName() << RED BOLD " has no more energy! 🤦" CLR << std::endl;
	else if (this->getHp() < 1)
		std::cout << RED BOLD UNDL << this->getName() << RED BOLD " has no more hit points! 🫤" CLR << std::endl;
	else
	{
		std::cout << CYN BOLD UNDL << this->getName() << CYN BOLD "attacks and does " << this->getDmg() << " to " UNDL << target << CLR << "😱" << std::endl;
		this->_energy --;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << CYN BOLD "Oh no " << this->getName() << " took damage 😭" CLR << std::endl;
	this->setHp(this->getHp() - amount);
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->getEnergy() < 1)
		std::cout << RED BOLD UNDL << this->getName() << RED BOLD " has no more energy! 🤦" CLR << std::endl;
	else
	{
		std::cout << CYN BOLD "Yeepee " << this->getName() << " is healing 😸" CLR << std::endl;
		this->setHp(this->getHp() - amount);
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
