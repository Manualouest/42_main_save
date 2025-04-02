/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 12:11:03 by mbirou            #+#    #+#             */
/*   Updated: 2025/03/27 09:59:15 by mbirou           ###   ########.fr       */
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

template<typename T>
std::string	printContainer(T container)
{
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		PRINT CYN BOLD AND *it;
		if (++it != container.end())
			PRINT ", ";
		--it;
	}
	PRINT CLR;
	return ("");
}

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

		static std::vector<__uint64_t>	_jacob;

		template <typename T>
		static T	Ford(T &nums, const int &nbNums, const int &nbPair)
		{
			T	big = T(nbPair, 0);
			T	small = T(nbPair - (nbNums % 2), 0);
			PmergeMe::_setupPairs(big.begin(), small.begin(), nums.begin(), nums.begin() + nbNums - (nbNums % 2));
			if (nbNums % 2)
				big[nbPair - 1] = nums[nbNums - 1];
			try
			{PmergeMe::_checkIsSorted(big, big);}
			catch (...)
			{big = PmergeMe::Ford(big, big.size(), (int)ceil((big.size()) / 2.f));}
			PmergeMe::_jacobInsert(big, small);
			return(big);
		}

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
		static void	_jacobInsert(T &sorted, T &numsList)
		{
			int			left;
			int			right;
			int			mid;
			int			jI = 0;
			__uint64_t	i = 0;
			__uint64_t	nb = 0;

			while (numsList.size()> _jacob[jI])
			{
				i = 0;
				while (i < _jacob[jI])
				{
					left = 0;
					right = sorted.size();
					mid = _jacob[jI];
					if (mid >= right)
						mid = (right - left) / 2 + left;
					while (left < right)
					{
						if (sorted[mid] < (numsList[_jacob[jI] - i]))
							left = mid + 1;
						else
							right = mid - 1;
						mid = (left + right) / 2;
					}
					sorted.insert(sorted.begin() + mid + (sorted[mid] < (numsList[_jacob[jI] - i])), (numsList[_jacob[jI] - i]));
					numsList.erase(numsList.begin() + (_jacob[jI] - i));
					++i;
					++nb;
				}
				++jI;
			}
			while (numsList.size() > 0)
			{
				left = 0;
				right = sorted.size();
				mid = (left + right) / 2;
				if (mid >= right)
					mid = (right - left) / 2 + left;
				while (left < right)
				{
					if (sorted[mid] < (numsList[0]))
						left = mid + 1;
					else
						right = mid - 1;
					mid = (left + right) / 2;
				}
				sorted.insert(sorted.begin() + mid + (sorted[mid] < (numsList[0])), (numsList[0]));
				numsList.erase(numsList.begin());
				++nb;
			}
		}

		template <typename T>
		static void	_checkIsSorted(T sorted, T nums)
		{
			if (sorted.size() != nums.size())
				throw(PmergeMe::SortFailedException());
			for(typename T::iterator start = sorted.begin(); start != sorted.end() - 1; ++start)
				if (*start > *(start + 1))
					throw(PmergeMe::SortFailedException());
		}
};
