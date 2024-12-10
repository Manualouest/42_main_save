/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:21:41 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/10 14:42:34 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	_type = "WNA";
	PRINT GRN BOLD "WrongAnimal Constructor called" CLR ENDL;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src)
{
	PRINT GRN BOLD "WrongAnimal Copy constructor called" CLR ENDL;
	*this = src;
}

WrongAnimal	&WrongAnimal::operator =(const WrongAnimal &rhs)
{
	PRINT GRN BOLD "WrongAnimal Copy assignement operator called" CLR ENDL;
	if (this != &rhs)
		_type = rhs.getType();
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	PRINT RGB(200, 200, 0) BOLD "WrongAnimal Destructor called" CLR ENDL;
}

void	WrongAnimal::makeSound() const
{
	PRINT RED BOLD "Bro forgor to put the virtual in WrongAnimal (stoopid) 🤣" CLR ENDL;
}

const std::string	&WrongAnimal::getType() const
{
	return (_type);
}

void	WrongAnimal::setType(const std::string &type)
{
	_type = type;
}