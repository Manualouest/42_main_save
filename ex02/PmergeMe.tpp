/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:50:05 by mbirou            #+#    #+#             */
/*   Updated: 2025/02/25 17:01:52 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
void	PmergeMe::_setupPairs(T big, T small, T nums, T end)
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
int	PmergeMe::partition(T &container, const int &low, const int &high)
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
void	PmergeMe::quicksort(T &container, const int &low, const int &high)
{
	if (low < high)
	{
		int pivot = PmergeMe::partition(container, low, high);
		PmergeMe::quicksort(container, low, pivot - 1);
		PmergeMe::quicksort(container, pivot + 1, high);
	}
}

template <typename T>
void	PmergeMe::_jacobInsert(T &sorted, T &numsList, const __uint64_t &nbPair)
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
void	PmergeMe::_checkIsSorted(T start, T end)
{
	for(; start != end - 1; ++start)
		if (*start > *(start + 1))	
			throw(PmergeMe::SortFailedException());
}
