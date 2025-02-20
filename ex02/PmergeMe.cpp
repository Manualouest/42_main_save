/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:32:35 by mbirou            #+#    #+#             */
/*   Updated: 2025/02/20 18:59:41 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// std::vector<std::pair<int, int> > PmergeMe::_vec = std::vector<std::pair<int, int> >();
std::pair<std::vector<int>, std::vector<int> > PmergeMe::_vec = std::pair<std::vector<int>, std::vector<int> >();
std::deque<std::pair<int, int> > PmergeMe::_deq = std::deque<std::pair<int, int> >();

void	printTime(const timespec &time1, const timespec &time0)
{
	double	time = (time1.tv_sec - time0.tv_sec) + (time1.tv_nsec - time0.tv_nsec) / 1000000000.;
	if (time > 1)
		PRINT CYN BOLD "Took " AND std::fixed AND std::setprecision(9) AND time AND " seconds." CENDL;
	else if (time * 1000 > 1)
		PRINT CYN BOLD "Took " AND std::fixed AND std::setprecision(6) AND time * 1000 AND " miliseconds." CENDL;
	else if (time * 1000000 > 1)
		PRINT CYN BOLD "Took " AND std::fixed AND std::setprecision(3) AND time * 1000000 AND " microseconds." CENDL;
	else if (time * 1000000000 > 1)
		PRINT CYN BOLD "Took " AND time * 1000000000 AND " nanoseconds." CENDL;
}

std::vector<int>	getInts(const int &nbNums, char **args)
{
	std::vector<int>			nums (nbNums, -1);
	std::vector<int>::iterator	it = --nums.begin();
	char						*safety;

	for (int i = 0; i < nbNums; ++i)
	{
		nums[i] = strtod(args[i], &safety);
		if (*safety != 0 || nums[i] < 0
			|| nums[i] != std::floor(strtod(args[i], &safety))
			|| (i > 0 && (*std::find(nums.begin(), it, nums[i])) == nums[i]))
			throw (PmergeMe::InvalidArgException());
		++it;
	}
	NEWL;
	return nums;
}

int	partition(std::vector<int> &vnums, std::vector<int> &vec, int low, int high)
{
	int	pivot = vec[high];
	int	i = low - 1;

	for (int ii = low; ii < high; ++ii)
	{
		if (vec[ii] <= pivot)
		{
			++i;
			std::swap(vec[i], vec[ii]);
		}
	}
	vnums[i + 1 - low] = vec[high];
	std::swap(vec[i + 1], vec[high]);
	return (i + 1);
}

void	quicksort(std::vector<int> &vnums, std::vector<int> &vec, int low, int high)
{
	if (low < high)
	{
		int pivot = partition(vnums, vec, low, high);
		quicksort(vnums, vec, low, pivot - 1);
		quicksort(vnums, vec, pivot + 1, high);
	}
}

void	PmergeMe::sort(int nbNums, char **args)
{
	std::vector<int>	vnums = getInts(nbNums, args);
	std::vector<int>	dnums(vnums.begin(), vnums.end());
	int					nbPair = (int)ceil(nbNums / 2.f);
	timespec			start;
	timespec			end;

	PRINT GRN BOLD AND nbPair CENDL;
	_vec =  std::pair<std::vector<int>, std::vector<int> >(std::vector<int>(nbPair, -1), std::vector<int>(nbPair - (nbNums % 2), -1));
	// _deq =  std::deque<std::pair<int, int> >(nbPair, std::pair<int, int>(-1, -1));

	timespec_get(&start, TIME_UTC);
	PmergeMe::_setupPairs(_vec.first.begin(), _vec.second.begin(), vnums.begin(), vnums.begin() + nbNums - (nbNums % 2));
	if (nbNums % 2)
		_vec.first[nbPair - 1] = vnums[nbNums - 1];
	vnums.erase(vnums.begin() + nbPair, vnums.end());
	quicksort(vnums, _vec.first, 0, nbPair - 1);
	timespec_get(&end, TIME_UTC);

	for (std::vector<int>::iterator it = _vec.first.begin(); it != _vec.first.end(); ++it)
	{
		PRINT CYN BOLD AND *it AND ", ";
	}
	for (std::vector<int>::iterator it = _vec.second.begin(); it != _vec.second.end(); ++it)
	{
		PRINT RED BOLD AND *it AND ", ";
	}
	NEWL;

	NEWL;
	printTime(end, start);
	NEWL;
}

void	PmergeMe::_setupPairs(std::vector<int>::iterator big, std::vector<int>::iterator small, std::vector<int>::iterator nums, const std::vector<int>::iterator &end)
{
	for (; nums != end; nums += 2)
	{
		*nums > *(nums + 1) ? (*big = *nums, *small = *(nums + 1)) : (*small = *nums, *big = *(nums + 1));
		++big;
		++small;
	}
}

const char	*PmergeMe::InvalidArgException::what() const throw()
{
	return (RED BOLD "There is an invalid argument." CLR);
}

// int	partition(std::vector<std::pair<int, int> > &vec, int low, int high)
// {
// 	int	pivot = vec[high].first;
// 	int	i = low - 1;

// 	for (int ii = low; ii < high; ++ii)
// 	{
// 		if (vec[ii].first <= pivot)
// 		{
// 			++i;
// 			std::swap(vec[i].first, vec[ii].first);
// 		}
// 	}
// 	std::swap(vec[i + 1].first, vec[high].first);
// 	return (i + 1);
// }

// void	quicksort(std::vector<std::pair<int, int> > &vec, int low, int high)
// {
// 	if (low < high)
// 	{
// 		int pivot = partition(vec, low, high);
// 		quicksort(vec, low, pivot - 1);
// 		quicksort(vec, pivot + 1, high);
// 	}
// }

// void	PmergeMe::sort(int nbNums, char **args)
// {
// 	std::vector<int>	vnums = getInts(nbNums, args);
// 	std::vector<int>	dnums(vnums.begin(), vnums.end());
// 	int					nbPair = (int)ceil(nbNums / 2.f);
// 	timespec			start;
// 	timespec			end;

// 	_vec =  std::vector<std::pair<int, int> >(nbPair, std::pair<int, int>(-1, -1));
// 	_deq =  std::deque<std::pair<int, int> >(nbPair, std::pair<int, int>(-1, -1));

// 	timespec_get(&start, TIME_UTC);
// 	PmergeMe::_setupPairs(_vec.begin(), vnums.begin(), vnums.end());
// 	quicksort(_vec, 0, nbPair - 1);
// 	timespec_get(&end, TIME_UTC);

// 	// for (std::vector<std::pair<int, int> >::iterator it = _vec.begin(); it != _vec.end() - 1; ++it)
// 	// {
// 	// 	PRINT BOLD AND ((*it).first < (*(it + 1)).first) AND ", ";
// 	// }

// 	NEWL;
// 	printTime(end, start);
// 	NEWL;
// }

// void	PmergeMe::_setupPairs(std::vector<std::pair<int, int> >::iterator pair, std::vector<int>::iterator nums, const std::vector<int>::iterator &end)
// {
// 	for (; nums != end; nums += 2)
// 	{
// 		if (*nums > *(nums + 1))
// 			*pair = std::pair<int, int> (*nums, *(nums + 1));
// 		else
// 			*pair = std::pair<int, int> (*(nums + 1), *nums);
// 		++pair;
// 	}
// }
