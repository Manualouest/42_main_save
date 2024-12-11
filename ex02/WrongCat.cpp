/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:18:48 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/11 14:55:33 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	PRINT GRN BOLD "WrongCat Constructor called" CLR ENDL;
}

WrongCat::WrongCat(const WrongCat &src)
{
	PRINT GRN BOLD "WrongCat Copy constructor called" CLR ENDL;
	*this = src;
}

WrongCat	&WrongCat::operator =(const WrongCat &rhs)
{
	PRINT GRN BOLD "WrongCat Copy assignement operator called" CLR ENDL;
	if (this != &rhs)
		_type = rhs.getType();
	return (*this);
}

WrongCat::~WrongCat()
{
	PRINT RGB(200, 200, 0) BOLD "WrongCat Touched water" CLR ENDL;
}

void	WrongCat::makeSound() const
{
	PRINT CYN BOLD "Bonjour 🐱" CLR ENDL;
}
