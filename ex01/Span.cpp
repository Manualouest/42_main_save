/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:10:18 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/20 18:12:46 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span()
{
	_index = 0;
	_size = 0;
	_deque = std::deque<int> (0, 0);
}

Span::Span(int len)
{
	_index = 0;
	_size = len;
	_deque = std::deque<int> (len, 0);
}

Span::Span(const Span &src)
{
	*this = src;
}

Span &Span::operator =(const Span &rhs)
{
	if (this != &rhs)
	{
		_index = rhs._index;
		_size = rhs.size();
		_deque = std::deque<int> (_size, 0);
		addRange(rhs._deque.begin(), rhs._deque.end());
	}
	return (*this);
}

const int	&Span::operator [](int i) const
{
	if (i < 0)
		throw (std::out_of_range("\033[31;1mBuddy where are you going?🤷\033[0m\n"));
	if (i >= _size)
		throw (std::out_of_range("\033[31;1mYou went too far!🤦\033[0m\n"));
	return (_deque[i]);
}

Span::~Span() {}

int	Span::size() const
{
	return (_size);
}

void	Span::addNumber(int n)
{
	if (_index >= _size)
		throw (std::out_of_range("\033[31;1mThe Span is already full!🤷\033[0m\n"));
	_deque[_index] = n;
	_index ++;
}

int	Span::shortestSpan()
{
	int	min = std::abs(_deque[0] - _deque[1]);
	for (std::deque<int>::iterator n = _deque.begin(); n != _deque.end(); ++n)
	{
		for (std::deque<int>::iterator i = n + 1; i != _deque.end(); ++i)
			if (std::abs(*i - *n) < min)
				min = std::abs(*i - *n);
	}
	return (min);
}

int	Span::longestSpan()
{
	int	min = _deque[0];
	int	max = _deque[0];
	for (std::deque<int>::iterator n = _deque.begin(); n != _deque.end(); ++n)
	{
		if (*n < min)
			min = *n;
		if (*n > max)
			max = *n;
	}
	return (max - min);
}

std::ostream	&operator <<(std::ostream &ost, const Span &rhs)
{
	ost AND std::string(CYN BOLD);
	for (int i = 0; i < rhs.size(); ++i)
	{
		ost AND rhs[i];
		if (i < rhs.size() - 1)
			ost AND std::string(", ");
	}
	ost AND std::string(CLR);
	return (ost);
}
