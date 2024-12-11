/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:47:48 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/11 15:39:48 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	_type = "NA";
	PRINT GRN BOLD "Animal Constructor called" CLR ENDL;
}

Animal::Animal(const Animal &src)
{
	PRINT GRN BOLD "Animal Copy constructor called" CLR ENDL;
	*this = src;
}

Animal	&Animal::operator =(const Animal &rhs)
{
	PRINT GRN BOLD "Animal Copy assignement operator called" CLR ENDL;
	if (this != &rhs)
		_type = rhs.getType();
	return (*this);
}

Animal::~Animal()
{
	PRINT RGB(200, 200, 0) BOLD "Animal Died" CLR ENDL;
}

void	Animal::makeSound() const
{
	PRINT RED BOLD "Bro forgor to add an animal (stoopid) 🤣" CLR ENDL;
}

const std::string	&Animal::getType() const
{
	return (_type);
}

void	Animal::setType(const std::string &type)
{
	_type = type;
}
