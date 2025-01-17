/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:53:15 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/17 17:06:31 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
#include <spellBook.hpp>

class Data
{
	public:
		Data();
		Data(const int &id, const std::string &type);
		Data(const Data &src);
		Data	&operator =(const Data &rhs);
		bool	operator ==(const Data &rhs);
		~Data();

		int	getId() const;
		std::string	getType() const;
	
	private:
		int			_id;
		std::string	_type;
};

std::ostream	&operator <<(std::ostream &ost, const Data &rhs);
