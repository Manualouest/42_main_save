/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:40:25 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/20 08:39:15 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <stdexcept>
# include <string>

template <class C>
class	Array
{
	public:
		Array() : _len(0), _array(NULL) {}
		Array(int len) : _len(len), _array(new C[len])
		{
			for (int i = 0; i < _len; ++i)
				_array[i] = 0;
		}
		
		Array(const Array &src) : _len(0), _array(NULL) {*this = src;}
		Array	&operator =(const Array &rhs)
		{
			if (this != &rhs)
			{
				_len = rhs._len;
				if (_len != 0)
					delete []_array;
				_array = new C[_len];
				for (int i = 0; i < _len; ++i)
					_array[i] = rhs[i];
			}
			return (*this);
		}

		C	&operator [](int i) const
		{
			if (i < 0)
				throw (std::out_of_range("\033[31;1mBuddy where are you going?🤷\033[0m\n"));
			if (i >= _len)
				throw (std::out_of_range("\033[31;1mYou went too far!🤦\033[0m\n"));
			return (_array[i]);
		}

		~Array() {delete []_array;}


		int	size() const {return (_len);}

	private:
		int _len;
		C	*_array;
};

template <class C>
std::ostream	&operator<<(std::ostream &os, const Array<C> &rhs)
{
	int	len = rhs.size();
	for (int i = 0; i < len - 1; ++i)
		os AND CYN BOLD AND rhs[i] AND ", ";
	os AND rhs[len - 1] AND CLR;
	return (os);
}
