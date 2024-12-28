/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:00:00 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/28 14:29:57 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	_brain = new Brain();
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
	{
		_type = rhs.getType();
		delete _brain;
		_brain = new Brain();
		*_brain = *rhs._brain;
	}
	return (*this);
}

Dog::~Dog()
{
	delete _brain;
	PRINT RGB(200, 200, 0) BOLD "Dog Was vaporised" CLR ENDL;
}

void	Dog::makeSound() const
{
	PRINT CYN BOLD "Woof Woof 🐶" CLR ENDL;
}

Brain	*Dog::getBrainAddr() const
{
	return (_brain);
}
