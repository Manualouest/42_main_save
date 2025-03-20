/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:14:09 by mbirou            #+#    #+#             */
/*   Updated: 2025/03/20 10:36:52 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iterator>
#include "spellBook.hpp"

template <class T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}

		MutantStack(const MutantStack &src) {*this = src;}
		MutantStack &operator =(const MutantStack<T> &rhs)
		{
			this->std::stack<T>::operator=(std::stack<T>(rhs.c));
			return (*this);
		}

		MutantStack(const std::stack<T> &src) {*this = src;}
		MutantStack &operator =(const std::stack<T> &rhs)
		{
			this->std::stack<T>::operator=(rhs);
			return (*this);
		}

		~MutantStack() {}

		typedef typename std::stack<T>::container_type::iterator				iterator;
		typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

		iterator				begin() {return (this->c.begin());}
		const_iterator			cbegin() {return (this->c.cbegin());}
		iterator				end() {return (this->c.end());}
		const_iterator			cend() {return (this->c.cend());}
		reverse_iterator		rbegin() {return (this->c.rbegin());}
		const_reverse_iterator	crbegin() {return (this->c.crbegin());}
		reverse_iterator		rend() {return (this->c.rend());}
		const_reverse_iterator	crend() {return (this->c.crend());}
};
