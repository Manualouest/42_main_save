/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 14:27:00 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/28 18:28:12 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
	_name = "Shadow Wizard";
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	_invIndex = 0;
	_storageLen = 0;
	_storage = new AMateria*[_storageLen];
}

Character::Character(const std::string &name)
{
	_name = name;
	for (int i = 0; i < 4; ++i)
		_inventory[i] = NULL;
	_invIndex = 0;
	_storageLen = 0;
	_storage = new AMateria*[_storageLen];
}

Character::Character(const Character &src)
{
	*this = src;
}

Character	&Character::operator =(const Character &rhs)
{
	PRINT "HEY" ENDL;
	if (this != &rhs)
	{
		_name = rhs.getName();
		for (int i = 0; i < _storageLen; ++i)
			if (_storage[i])
				delete (_storage[i]);
		delete [] _storage;
		_storage = new AMateria*[rhs._invIndex];
		for (int i = 0; i < rhs._invIndex; ++i)
		{
			_storage[i] = rhs._inventory[i]->clone();
			_inventory[i] = _storage[i];
		}
		for (int i = rhs._invIndex; i < 4; ++i)
			_inventory[i] = NULL;
		_storageLen = rhs._invIndex;
	}
	return (*this);
}

Character::~Character()
{
	for (int i = 0; i < _storageLen; ++i)
		if (_storage[i])
			delete (_storage[i]);
	delete [] _storage;
}

std::string const	&Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	if (!m)
	{
		PRINT RED BOLD "Why NULL?" CLR ENDL;
		PRINT RED BOLD "😐\n≤))≥\n_| \\_ " CLR ENDL;
		NEWL;
	}
	else
	{
		AMateria	**temp = new AMateria*[_storageLen + 1];
		for (int i = 0; i < _storageLen; ++i)
			temp[i] = _storage[i];
		delete [] _storage;
		temp[_storageLen] = m;
		_storage = temp;
		if (_invIndex == 4)
		{
			PRINT RED BOLD "Mr " UNDL AND getName() AND RED BOLD " you already have 4 Materias equiped" CLR ENDL;
			PRINT RED BOLD "😐\n≤))≥\n_| \\_ " CLR ENDL;
			NEWL;
		}
		else
		{
			_inventory[_invIndex] = temp[_storageLen];
			_invIndex ++;
		}
		_storageLen ++;
	}
}

void	Character::unequip(int idx)
{
	if (_invIndex == 0)
	{
		PRINT RED BOLD "Mr " UNDL AND getName() AND RED BOLD " you're broke, you have nothing to unequip" CLR ENDL;
		PRINT RED BOLD "💀\n≤))≥\n_| \\_ " CLR ENDL;
		NEWL;
	}
	else if (idx < 0 || idx >= _invIndex)
	{
		PRINT RED BOLD "Index is invalid" CLR ENDL;
		PRINT RED BOLD "😐\n≤))≥\n_| \\_ " CLR ENDL;
		NEWL;
	}
	else
	{
		for (int i = idx; i < 3; ++i)
			_inventory[i] = _inventory[i + 1];
		_inventory[3] = NULL;
		_invIndex --;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if (_invIndex == 0)
	{
		PRINT RED BOLD "Mr " UNDL AND getName() AND RED BOLD " you're broke, you have nothing to use" CLR ENDL;
		PRINT RED BOLD "💀\n≤))≥\n_| \\_ " CLR ENDL;
		NEWL;
	}
	else if (idx < 0 || idx >= _invIndex)
	{
		PRINT RED BOLD "Index is invalid" CLR ENDL;
		PRINT RED BOLD "😐\n≤))≥\n_| \\_ " CLR ENDL;
		NEWL;
	}
	else
	{
		PRINT CYN BOLD AND getName() AND " " CLR;
		_inventory[idx]->use(target);
		NEWL;
	}
}
