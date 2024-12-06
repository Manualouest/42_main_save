/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:41:11 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/06 14:50:23 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point()
{
	this->_x = 0;
	this->_y = 0;
}

Point::Point(const float &x, const float &y)
{
	this->_x = x;
	this->_y = y;
}

Point::Point(const Point &point) : _x(0), _y(0)
{
	*this=point;
}

Point	&Point::operator =(const Point &rhs)
{
	if (this != &rhs)
	{
		this->_x = rhs.getX();
		this->_y = rhs.getY();
	}
	return (*this);
}

Point::~Point()
{
}

const Fixed	&Point::getX() const
{
	return (this->_x);
}

const Fixed	&Point::getY() const
{
	return (this->_y);
}
