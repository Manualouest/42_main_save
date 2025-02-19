/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:32:35 by mbirou            #+#    #+#             */
/*   Updated: 2025/02/19 12:53:25 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<std::pair<int, int> > PmergeMe::_vec = std::vector<std::pair<int, int> >();
std::deque<std::pair<int, int> > PmergeMe::_deq = std::deque<std::pair<int, int> >();

std::vector<int>	getInts(const int &nbNums, const char **args)
{
	std::vector<int>			nums (nbNums, -1);
	std::vector<int>::iterator	it = --nums.begin();
	char						*safety;

	for (int i = 0; i < nbNums; ++i)
	{
		nums[i] = strtod(args[i], &safety);
		if (*safety != 0 || nums[i] < 0
			|| nums[i] != std::floor(strtod(args[i], &safety))
			|| (*std::find(nums.begin(), it, nums[i])) == nums[i])
			throw (PmergeMe::InvalidArgException());
		++it;
	}
	for (std::vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
	{
		PRINT BOLD AND *it AND ", ";
	}
	NEWL;
	return nums;
}

void	PmergeMe::sort(int nbNums, char **args)
{
	std::vector<int>	vnums = getInts(nbNums, args);
	std::vector<int>	dnums(vnums.begin(), vnums.end());
	std::time_t			start;

	std::time(&start);
	PmergeMe::_setupPairs(vnums, ceil(nbNums / 2.f));
}

void	PmergeMe::_setupPairs(std::vector<int> vnums, const int &nbPairs)
{
	_vec =  std::vector<pair<int, int> >(std::pair<int, int>(-1, -1), nbPairs)
}

const char	*PmergeMe::InvalidArgException::what() const throw()
{
	return (RED BOLD "There is an invalid argument." CLR);
}
