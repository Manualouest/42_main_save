/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:27:00 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/13 18:03:50 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	_name = "Shadow Wizard";
}

Character::Character(const Character &src)
{
	*this = src;
}

Character	&Character::operator =(const Character &rhs)
{
	if (this != &rhs)
	{
		_name = rhs.getName();
		for (int i = 0; i < 4; ++i)
			
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < 4; ++i)
		if (_inventory[i])
			delete (_inventory[i]);
}

std::string const	&Character::getName() const
{
	
}

void	Character::equip(AMateria* m)
{
	
}

void	Character::unequip(int idx)
{
	
}

void	Character::use(int idx, ICharacter& target)
{
	
}
