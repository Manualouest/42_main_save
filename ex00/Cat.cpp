/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:02:20 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/11 15:41:37 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	PRINT GRN BOLD "Cat Constructor called" CLR ENDL;
}

Cat::Cat(const Cat &src)
{
	PRINT GRN BOLD "Cat Copy constructor called" CLR ENDL;
	*this = src;
}

Cat	&Cat::operator =(const Cat &rhs)
{
	PRINT GRN BOLD "Cat Copy assignement operator called" CLR ENDL;
	if (this != &rhs)
		_type = rhs.getType();
	return (*this);
}

Cat::~Cat()
{
	PRINT RGB(200, 200, 0) BOLD "Cat Touched water" CLR ENDL;
}

void	Cat::makeSound() const
{
	PRINT CYN BOLD "Rrrrrrrreow 🐱🥖" CLR ENDL;
}