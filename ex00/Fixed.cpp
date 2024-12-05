/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:51:03 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/05 12:35:29 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _num(0)
{
	std::cout << "\033[32;1mDefault constuctor called\033[0m" << std::endl;
}

Fixed::Fixed(const Fixed &src) : _num(0)
{
	std::cout << "\033[32;1mCopy constuctor called\033[0m" << std::endl;
	*this = src;
}

Fixed	&Fixed::operator=(const Fixed &rhs)
{
	std::cout << "\033[32;1mCopy assignement operator called\033[0m" << std::endl;
	if (this != &rhs)
		this->_num = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "\033[1;38;2;200;200;0mDestructor called\033[0m" << std::endl;
}

int	Fixed::getRawBits() const
{
	std::cout << "\033[36;1mgetRawBits member function called\033[0m" << std::endl;
	return (this->_num);
}


void	Fixed::setRawBits(int const raw)
{
	std::cout << "\033[36;1msetRawBits member function called\033[0m" << std::endl;
	this->_num = raw;
}
