/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:47:48 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/11 16:00:32 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	_type = "NA";
	PRINT GRN BOLD "AAnimal Constructor called" CLR ENDL;
}

AAnimal::AAnimal(const AAnimal &src)
{
	PRINT GRN BOLD "AAnimal Copy constructor called" CLR ENDL;
	*this = src;
}

AAnimal	&AAnimal::operator =(const AAnimal &rhs)
{
	PRINT GRN BOLD "Abstract Animal Copy assignement operator called" CLR ENDL;
	if (this != &rhs)
		_type = rhs.getType();
	return (*this);
}

AAnimal::~AAnimal()
{
	PRINT RGB(200, 200, 0) BOLD "Abstract Animal Died" CLR ENDL;
}

void	AAnimal::makeSound() const
{
	PRINT RED BOLD "Bro forgor to add an animal (stoopid) 🤣" CLR ENDL;
}

const std::string	&AAnimal::getType() const
{
	return (_type);
}

void	AAnimal::setType(const std::string &type)
{
	_type = type;
}
