/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:11:03 by mbirou            #+#    #+#             */
/*   Updated: 2025/02/25 17:57:44 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <spellBook.hpp>
#include <utility>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <iterator>
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
		class SortFailedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe operator =(const PmergeMe &rhs);
		~PmergeMe();

		static void	_setupJacob(const __uint64_t &nbNum);

		template <typename T>
		static void	_setupPairs(T big, T small, T nums, T end);

		template <typename T>
		static int	partition(T &container, const int &low, const int &high);

		template <typename T>
		static void	quicksort(T &container, const int &low, const int &high);

		template <typename T>
		static void	_jacobInsert(T &sorted, T &nums, const __uint64_t &nbPair);

		template <typename T>
		static void	_checkIsSorted(T start, T end);

		static std::pair<std::vector<__uint64_t>, std::vector<__uint64_t> >	_vec;
		static std::pair<std::deque<__uint64_t>, std::deque<__uint64_t> >	_deq;
		static std::vector<__uint64_t>										_jacob;
};

#include "PmergeMe.tpp"
