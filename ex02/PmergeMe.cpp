/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:32:35 by mbirou            #+#    #+#             */
/*   Updated: 2025/02/25 18:05:30 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::pair<std::vector<__uint64_t>, std::vector<__uint64_t> >	PmergeMe::_vec = std::pair<std::vector<__uint64_t>, std::vector<__uint64_t> >();
std::pair<std::deque<__uint64_t>, std::deque<__uint64_t> >		PmergeMe::_deq = std::pair<std::deque<__uint64_t>, std::deque<__uint64_t> >();
std::vector<__uint64_t>											PmergeMe::_jacob = std::vector<__uint64_t>();

void	printTime(const timespec &time1, const timespec &time0)
{
	double	time = (time1.tv_sec - time0.tv_sec) + (time1.tv_nsec - time0.tv_nsec) / 1000000000.;
	if (time > 1)
		PRINT CYN BOLD "Took " AND std::fixed AND std::setprecision(9) AND time AND " seconds";
	else if (time * 1000 > 1)
		PRINT CYN BOLD "Took " AND std::fixed AND std::setprecision(6) AND time * 1000 AND " miliseconds";
	else if (time * 1000000 > 1)
		PRINT CYN BOLD "Took " AND std::fixed AND std::setprecision(3) AND time * 1000000 AND " microseconds";
	else if (time * 1000000000 > 1)
		PRINT CYN BOLD "Took " AND time * 1000000000 AND " nanoseconds";
}

std::vector<__uint64_t>	getInts(const __uint64_t &nbNums, char **args)
{
	std::vector<__uint64_t>			nums (nbNums, -1);
	std::vector<__uint64_t>::iterator	it = --nums.begin();
	char						*safety;

	for (__uint64_t i = 0; i < nbNums; ++i)
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

void	PmergeMe::_setupJacob(const __uint64_t &nbNum)
{
	__uint64_t jacobMax = 2;
	_jacob.insert(_jacob.end(), 1);
	_jacob.insert(_jacob.end(), 1);
	for (int i = 2; jacobMax < nbNum; ++i)
	{
		_jacob.insert(_jacob.end(), _jacob[i - 1] + 2 * _jacob[i - 2]);
		jacobMax += _jacob[i];
	}
}

void	PmergeMe::sort(int nbNums, char **args)
{
	bool	printContainers	= false;
	if (!std::strcmp(args[0], "-p"))
	{
		--nbNums;
		args ++;
		printContainers = true;
	}
	std::vector<__uint64_t>	vnums = getInts(nbNums, args);
	std::deque<__uint64_t>	dnums(vnums.begin(), vnums.end());
	int						nbPair = (int)ceil(nbNums / 2.f);
	timespec				vStart;
	timespec				vEnd;
	timespec				dStart;
	timespec				dEnd;

	_setupJacob(nbNums);
	_vec =  std::pair<std::vector<__uint64_t>, std::vector<__uint64_t> >(std::vector<__uint64_t>(nbPair, 0), std::vector<__uint64_t>(nbPair - (nbNums % 2), 0));
	_deq =  std::pair<std::deque<__uint64_t>, std::deque<__uint64_t> >(std::deque<__uint64_t>(nbPair, 0), std::deque<__uint64_t>(nbPair - (nbNums % 2), 0));
	{
		timespec_get(&vStart, TIME_UTC);
		PmergeMe::_setupPairs(_vec.first.begin(), _vec.second.begin(), vnums.begin(), vnums.begin() + nbNums - (nbNums % 2));
		if (nbNums % 2)
		_vec.first[nbPair - 1] = vnums[nbNums - 1];
		PmergeMe::quicksort(_vec.first, 0, nbPair - 1);
		PmergeMe::_jacobInsert(_vec.first, _vec.second, nbPair);
		timespec_get(&vEnd, TIME_UTC);
	}
	{
		timespec_get(&dStart, TIME_UTC);
		PmergeMe::_setupPairs(_deq.first.begin(), _deq.second.begin(), dnums.begin(), dnums.begin() + nbNums - (nbNums % 2));
		if (nbNums % 2)
		_deq.first[nbPair - 1] = dnums[nbNums - 1];
		PmergeMe::quicksort(_deq.first, 0, nbPair - 1);
		PmergeMe::_jacobInsert(_deq.first, _deq.second, nbPair);
		timespec_get(&dEnd, TIME_UTC);
	}
	{
		if (printContainers)
		{
			PRINT DSTR UNDL BOLD "Vector:" TAB YLW BOLD ENDL;
			for (std::vector<__uint64_t>::iterator	it = _vec.first.begin(); it != _vec.first.end(); ++it)
				PRINT *it AND (it + 1 != _vec.first.end() ? ", ": CLR);
			NEWL;
			PRINT DSTR UNDL BOLD "Deque:" TAB YLW BOLD ENDL;
			for (std::deque<__uint64_t>::iterator	it = _deq.first.begin(); it != _deq.first.end(); ++it)
					PRINT *it AND (it + 1 != _deq.first.end() ? ", ": CLR);
			NEWL;
			NEWL;
		}
		PRINT CYN UNDL BOLD "Vector part" CYN BOLD ": ";
		printTime(vEnd, vStart);
		PRINT " to sort " AND nbNums AND " elements" CENDL;
		PRINT TAB CYN UNDL BOLD "Before" CYN BOLD ": ";
		for (std::vector<__uint64_t>::iterator	it = vnums.begin(); it != vnums.end() && std::distance(vnums.begin(), it) < 5; ++it)
		PRINT CYN BOLD AND *it AND ((it + 1 != vnums.end() && std::distance(vnums.begin(), it) < 4) ? ", ": (it + 1 != vnums.end() ? " [...]" CLR: CLR));
		NEWL;
		PRINT TAB CYN UNDL BOLD "After" CYN BOLD ": ";
		for (std::vector<__uint64_t>::iterator	it = _vec.first.begin(); it != _vec.first.end() && std::distance(_vec.first.begin(), it) < 5; ++it)
		PRINT CYN BOLD AND *it AND ((it + 1 != _vec.first.end() && std::distance(_vec.first.begin(), it) < 4) ? ", ": (it + 1 != _vec.first.end() ? " [...]" CLR: CLR));
		NEWL;
		NEWL;
		PRINT CYN UNDL BOLD "Deque part" CYN BOLD ": ";
		printTime(dEnd, dStart);
		PRINT " to sort " AND nbNums AND " elements" CENDL;
		PRINT TAB CYN UNDL BOLD "Before" CYN BOLD ": ";
		for (std::deque<__uint64_t>::iterator	it = dnums.begin(); it != dnums.end() && std::distance(dnums.begin(), it) < 5; ++it)
			PRINT CYN BOLD AND *it AND ((it + 1 != dnums.end() && std::distance(dnums.begin(), it) < 4) ? ", ": (it + 1 != dnums.end() ? " [...]" CLR: CLR));
		NEWL;
		PRINT TAB CYN UNDL BOLD "After" CYN BOLD ": ";
		for (std::deque<__uint64_t>::iterator	it = _deq.first.begin(); it != _deq.first.end() && std::distance(_deq.first.begin(), it) < 5; ++it)
			PRINT CYN BOLD AND *it AND ((it + 1 != _deq.first.end() && std::distance(_deq.first.begin(), it) < 4) ? ", ": (it + 1 != _deq.first.end() ? " [...]" CLR: CLR));
		NEWL;
	}
	PmergeMe::_checkIsSorted(_vec.first.begin(), _vec.first.end());
	PmergeMe::_checkIsSorted(_deq.first.begin(), _deq.first.end());
}

const char	*PmergeMe::InvalidArgException::what() const throw()
{
	return (RED BOLD "There is an invalid argument." CLR);
}
const char	*PmergeMe::SortFailedException::what() const throw()
{
	return (RED BOLD "Somehow the merge sort failed 🤔." CLR);
}
