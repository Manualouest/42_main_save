/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:11:03 by mbirou            #+#    #+#             */
/*   Updated: 2025/03/21 14:32:34 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
#include <vector>
#include <deque>
#include <spellBook.hpp>

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

		static std::pair<std::vector<__uint64_t>, std::vector<__uint64_t> >	_vec;
		static std::pair<std::deque<__uint64_t>, std::deque<__uint64_t> >	_deq;
		static std::vector<__uint64_t>										_jacob;

		template <typename T>
		static void	_setupPairs(T big, T small, T nums, T end)
		{
			for (; nums != end; nums += 2)
			{
				if (*nums > *(nums + 1))
				{
					*big = *nums;
					*small = *(nums + 1);
				}
				else
				{
					*small = *nums;
					*big = *(nums + 1);
				}
				++big;
				++small;
			}
		}

		template <typename T>
		static int	partition(T &container, const int &low, const int &high)
		{
			__uint64_t	pivot = container[high];
			int	i = low - 1;

			for (int ii = low; ii < high; ++ii)
				if (container[ii] <= pivot)
					std::swap(container[++i], container[ii]);
			std::swap(container[i + 1], container[high]);
			return (i + 1);
		}

		template <typename T>
		static void	quicksort(T &container, const int &low, const int &high)
		{
			if (low < high)
			{
				int pivot = PmergeMe::partition(container, low, high);
				PmergeMe::quicksort(container, low, pivot - 1);
				PmergeMe::quicksort(container, pivot + 1, high);
			}
		}

		template <typename T>
		static void	_jacobInsert(T &sorted, T &numsList, const __uint64_t &nbPair)
		{
			int			left;
			int			right;
			int			mid;
			int			jI = 0;
			__uint64_t	i = 0;
			__uint64_t	nb = 0;

			for(typename T::iterator nums = numsList.begin(); nums != numsList.end(); ++nums, ++nb, ++i)
			{
				left = 0;
				right = nbPair + nb;
				mid = _jacob[jI];
				if (mid >= right)
					mid = (right - left) / 2 + left;
				while (left < right)
				{
					if (sorted[mid] < *nums)
						left = mid + 1;
					else
						right = mid - 1;
					mid = (left + right) / 2;
				}
				sorted.insert(sorted.begin() + mid + (sorted[mid] < *nums), *nums);
				if (i == _jacob[jI])
				{
					i = 0;
					++jI;
				}
			}
		}

		template <typename T>
		static void	_checkIsSorted(T start, T end)
		{
			for(; start != end - 1; ++start)
				if (*start > *(start + 1))	
					throw(PmergeMe::SortFailedException());
		}
};
