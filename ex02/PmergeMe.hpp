/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:11:03 by mbirou            #+#    #+#             */
/*   Updated: 2025/02/20 18:26:07 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
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

		// static void	_setupPairs(std::vector<std::pair<int, int> >::iterator pair, std::vector<int>::iterator nums, const std::vector<int>::iterator &end);
		static void	_setupPairs(std::vector<int>::iterator big, std::vector<int>::iterator small, std::vector<int>::iterator nums, const std::vector<int>::iterator &end);
		// static std::vector<std::pair<int, int> >	_vec;
		static std::pair<std::vector<int>, std::vector<int> > _vec;
		static std::deque<std::pair<int, int> >		_deq;
		static std::vector<int>						_jacob;
};