/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:34:36 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/28 18:02:34 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i)
		_templates[i] = NULL;
	_storageLen = 0;
	_storage = new AMateria*[_storageLen];
}

MateriaSource::MateriaSource(const MateriaSource &src)
{
	*this = src;
}

MateriaSource	&MateriaSource::operator =(const MateriaSource &rhs)
{
	for (int i = 0; i < 4; ++i)
		PRINT i AND " " AND _templates[i] ENDL;
	if (this != &rhs)
	{
		for (int i = 0; i < _storageLen; ++i)
			if (_storage[i])
				delete _storage[i];
		delete [] _storage;
		_storage = new AMateria*[4];
		for (int i = 0; i < 4; ++i)
		{
			if (_templates[i])
				delete _templates[i];
			if (rhs._templates[i])
				_storage[i] = rhs._templates[i]->clone();
			else
				_storage[i] = NULL;
			_templates[i] = _storage[i];
		}
		for (_storageLen = 0; _storageLen < 4 && _storage[_storageLen]; ++_storageLen)
			;
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < _storageLen; ++i)
		if (_storage[i])
			delete _storage[i];
	delete [] _storage;
}

void MateriaSource::learnMateria(AMateria *materia)
{
	int	i;
	for (i = 0; i < 4 && _templates[i]; ++i)
		;
	if (!materia)
	{
		PRINT RED BOLD "Where template?" CLR ENDL;
		PRINT RED BOLD "😐\n≤))≥\n_| \\_ " CLR ENDL;
		NEWL;
	}
	else
	{
		AMateria	**temp = new AMateria*[_storageLen + 1];
		for (int i = 0; i < _storageLen; ++i)
			temp[i] = _storage[i];
		delete [] _storage;
		temp[_storageLen] = materia;
		_storage = temp;
		if (i == 4)
		{
			PRINT RED BOLD "You already have 4 templates" CLR ENDL;
			PRINT RED BOLD "😐\n≤))≥\n_| \\_ " CLR ENDL;
			NEWL;
		}
		else
			_templates[i] = temp[_storageLen];
		_storageLen ++;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4 && _templates[i]; ++i)
		if (_templates[i]->getType() == type)
			return (_templates[i]->clone());
	PRINT RED BOLD "What da hell is even " AND type AND CLR ENDL;
	PRINT RED BOLD "🤨\n≤))≥\n_| \\_ " CLR ENDL;
	NEWL;
	return (0);
}
