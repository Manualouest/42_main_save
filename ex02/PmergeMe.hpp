/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:11:03 by mbirou            #+#    #+#             */
/*   Updated: 2025/02/19 12:51:30 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <spellBook.hpp>
#include <utility>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <deque>

class PmergeMe
{
	public:
		static void sort(int nbNums, char **nums);

		class InvalidArgException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe operator =(const PmergeMe &rhs);
		~PmergeMe();

		static void	_setupPairs(std::vector<int> vnums, const int &nbPairs);

		static std::vector<std::pair<int, int> > _vec;
		static std::deque<std::pair<int, int> > _deq;
};