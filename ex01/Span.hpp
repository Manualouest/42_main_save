/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:44:02 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/30 00:50:28 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <algorithm>
# include <climits>
# include <iterator>
# include <deque>
# include "spellBook.hpp"

class Span
{
	public:
		Span();
		Span(int len);
		Span(const Span &src);
		Span &operator =(const Span &rhs);
		const int	&operator [](int i) const;
		~Span();

		int	size() const;
		void	addNumber(int n);
		int	shortestSpan();
		int	longestSpan();
		template<typename T>
		void	addRange(T start, T end)
		{
			if (_index + std::distance(start, end) > _size)
				throw(std::range_error("\033[31;1mThe range you tried to use is too big! 😑\033[0m\n"));
			_deque.insert(_deque.begin() + _index, start, end);
			_index += std::distance(start, end);
		}

	private:
		int				_index;
		int				_size;
		std::deque<int>	_deque;
};

std::ostream	&operator <<(std::ostream &ost, const Span &rhs);