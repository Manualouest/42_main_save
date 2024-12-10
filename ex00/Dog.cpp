/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:00:00 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/10 14:15:00 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	PRINT GRN BOLD "Dog Constructor called" CLR ENDL;
}

Dog::Dog(const Dog &src)
{
	PRINT GRN BOLD "Dog Copy constructor called" CLR ENDL;
	*this = src;
}

Dog	&Dog::operator =(const Dog &rhs)
{
	PRINT GRN BOLD "Dog Copy assignement operator called" CLR ENDL;
	if (this != &rhs)
		_type = rhs.getType();
	return (*this);
}

Dog::~Dog()
{
	PRINT RGB(200, 200, 0) BOLD "Dog Destructor called" CLR ENDL;
}

void	Dog::makeSound() const
{
	PRINT CYN BOLD "Woof Woof 🐶" CLR ENDL;
}
