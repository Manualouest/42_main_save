/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:58:25 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/17 17:07:25 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

Data::Data()
{
	_id = 0;
	_type = "None";
}

Data::Data(const int &id, const std::string &type)
{
	_id = id;
	_type = type;
}

Data::Data(const Data &src)
{
	*this = src;
}

Data	&Data::operator =(const Data &rhs)
{
	if (this != &rhs)
	{
		_id = rhs._id;
		_type = rhs._type;
	}
	return (*this);
}

bool	Data::operator ==(const Data &rhs)
{
	if (_id != rhs._id || _type != rhs._type)
		return (false);
	return (true);
}

Data::~Data()
{
}

int	Data::getId() const
{
	return(_id);
}

std::string	Data::getType() const
{
	return(_type);
}


std::ostream	&operator <<(std::ostream &ost, const Data &rhs)
{
	ost AND CYN BOLD "id: " AND rhs.getId() AND ", type: " AND rhs.getType() CENDL;
	return (ost);
}
