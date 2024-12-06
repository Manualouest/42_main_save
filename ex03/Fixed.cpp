/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:51:03 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/06 15:10:09 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _num(0)
{
}

Fixed::Fixed(const int &num)
{
	this->_num = num << this->_bit;
}

Fixed::Fixed(const float &num)
{
	this->_num = (int)roundf(num * (1 << this->_bit));
}

Fixed::Fixed(const Fixed &src) : _num(0)
{
	*this = src;
}

Fixed	&Fixed::operator =(const Fixed &rhs)
{
	if (this != &rhs)
		this->_num = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator >(const Fixed &rhs) const
{
	if (this->_num > rhs._num)
		return (true);
	return (false);
}

bool	Fixed::operator <(const Fixed &rhs) const
{
	if (this->_num < rhs._num)
		return (true);
	return (false);
}

bool	Fixed::operator >=(const Fixed &rhs) const
{
	if (this->_num >= rhs._num)
		return (true);
	return (false);
}

bool	Fixed::operator <=(const Fixed &rhs) const
{
	if (this->_num <= rhs._num)
		return (true);
	return (false);
}

bool	Fixed::operator ==(const Fixed &rhs) const
{
	if (this->_num == rhs._num)
		return (true);
	return (false);
}

bool	Fixed::operator !=(const Fixed &rhs) const
{
	if (this->_num != rhs._num)
		return (true);
	return (false);
}

Fixed	Fixed::operator +(const Fixed &rhs) const
{
	Fixed newNum(this->toFloat() + rhs.toFloat());
	return (newNum);
}

Fixed	Fixed::operator -(const Fixed &rhs) const
{
	Fixed newNum(this->toFloat() - rhs.toFloat());
	return (newNum);
}


Fixed	Fixed::operator *(const Fixed &rhs) const
{
	Fixed newNum(this->toFloat() * rhs.toFloat());
	return (newNum);
}


Fixed	Fixed::operator /(const Fixed &rhs) const
{
	Fixed newNum(this->toFloat() / rhs.toFloat());
	return (newNum);
}

Fixed	Fixed::operator ++(int)
{
	Fixed newNum;
	newNum.setRawBits(this->_num++);
	return (newNum);
}

Fixed	&Fixed::operator ++()
{
	this->_num ++;
	return (*this);
}

Fixed	Fixed::operator --(int)
{
	Fixed newNum;
	newNum.setRawBits(this->_num--);
	return (newNum);
}

Fixed	&Fixed::operator --()
{
	this->_num --;
	return (*this);
}

std::ostream	&operator <<(std::ostream &ost, const Fixed &rhs)
{
	ost << rhs.toFloat();
	return (ost);
}

Fixed::~Fixed()
{
}

int	Fixed::getRawBits() const
{
	return (this->_num);
}

void	Fixed::setRawBits(int const raw)
{
	this->_num = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_num / (1 << this->_bit));
}

int	Fixed::toInt(void) const
{
	return ((float)this->_num / (1 << this->_bit));
}

Fixed		&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() < b.toFloat())
		return (a);
	return (b);
}

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	return (b);
}

void	Fixed::Abs()
{
	if (this->_num < 0)
		this->_num *= -1;
}
