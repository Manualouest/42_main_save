/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:32:35 by mbirou            #+#    #+#             */
/*   Updated: 2025/03/27 09:54:49 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector<__uint64_t>											PmergeMe::_jacob = std::vector<__uint64_t>();

void	printTime(const timespec &time1, const timespec &time0)
{
	double	time = (time1.tv_sec - time0.tv_sec) + (time1.tv_nsec - time0.tv_nsec) / 1000000000.;
	if (time > 1)
		PRINT "Took " AND std::fixed AND std::setprecision(9) AND time AND " seconds";
	else if (time * 1000 > 1)
		PRINT "Took " AND std::fixed AND std::setprecision(6) AND time * 1000 AND " miliseconds";
	else if (time * 1000000 > 1)
		PRINT "Took " AND std::fixed AND std::setprecision(3) AND time * 1000000 AND " microseconds";
	else if (time * 1000000000 > 1)
		PRINT "Took " AND time * 1000000000 AND " nanoseconds";
}

std::vector<__uint64_t>	getInts(const __uint64_t &nbNums, char **args)
{
	std::vector<__uint64_t>				nums (nbNums, -1);
	std::vector<__uint64_t>::iterator	it = --nums.begin();
	char								*safety;

	for (__uint64_t i = 0; i < nbNums; ++i)
	{
		nums[i] = strtod(args[i], &safety);
		if (*safety != 0 || strtod(args[i], &safety) < 0
			|| nums[i] != std::floor(nums[i]))
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
	if (!std::strcmp(args[nbNums - 1], "-p"))
	{
		--nbNums;
		printContainers = true;
	}
	std::vector<__uint64_t>	vnums = getInts(nbNums, args);
	std::vector<__uint64_t>	resultvec;
	std::deque<__uint64_t>	dnums(vnums.begin(), vnums.end());
	std::deque<__uint64_t>	resultdeq;
	int						nbPair = (int)ceil(nbNums / 2.f);
	timespec				vStart;
	timespec				vEnd;
	timespec				dStart;
	timespec				dEnd;

	_setupJacob(nbNums);
	{
		timespec_get(&vStart, TIME_UTC);
		resultvec = PmergeMe::Ford(vnums, nbNums, nbPair);
		timespec_get(&vEnd, TIME_UTC);
	}
	{
		timespec_get(&dStart, TIME_UTC);
		resultdeq = PmergeMe::Ford(dnums, nbNums, nbPair);
		timespec_get(&dEnd, TIME_UTC);
	}
	{
		if (printContainers)
		{
			PRINT DSTR UNDL BOLD "Vector:" TAB YLW BOLD ENDL;
			for (std::vector<__uint64_t>::iterator	it = resultvec.begin(); it != resultvec.end(); ++it)
				PRINT *it AND (it + 1 != resultvec.end() ? ", ": CLR);
			NEWL;
			NEWL;
			PRINT DSTR UNDL BOLD "Deque:" TAB YLW BOLD ENDL;
			for (std::deque<__uint64_t>::iterator	it = resultdeq.begin(); it != resultdeq.end(); ++it)
					PRINT *it AND (it + 1 != resultdeq.end() ? ", ": CLR);
			NEWL;
			NEWL;
		}
		PRINT CYN UNDL BOLD "Vector" CYN BOLD ": ";
		printTime(vEnd, vStart);
		PRINT " to sort " AND nbNums AND " elements" CENDL;
		PRINT TAB CYN UNDL BOLD "Before" CYN BOLD ": ";
		for (std::vector<__uint64_t>::iterator	it = vnums.begin(); it != vnums.end() && std::distance(vnums.begin(), it) < 5; ++it)
		PRINT CYN BOLD AND *it AND ((it + 1 != vnums.end() && std::distance(vnums.begin(), it) < 4) ? ", ": (it + 1 != vnums.end() ? " [...]" CLR: CLR));
		NEWL;
		PRINT TAB CYN UNDL BOLD "After" CYN BOLD ": ";
		for (std::vector<__uint64_t>::iterator	it = resultvec.begin(); it != resultvec.end() && std::distance(resultvec.begin(), it) < 5; ++it)
		PRINT CYN BOLD AND *it AND ((it + 1 != resultvec.end() && std::distance(resultvec.begin(), it) < 4) ? ", ": (it + 1 != resultvec.end() ? " [...]" CLR: CLR));
		NEWL;
		NEWL;
		PRINT CYN UNDL BOLD "Deque" CYN BOLD ": ";
		printTime(dEnd, dStart);
		PRINT " to sort " AND nbNums AND " elements" CENDL;
		PRINT TAB CYN UNDL BOLD "Before" CYN BOLD ": ";
		for (std::deque<__uint64_t>::iterator	it = dnums.begin(); it != dnums.end() && std::distance(dnums.begin(), it) < 5; ++it)
			PRINT CYN BOLD AND *it AND ((it + 1 != dnums.end() && std::distance(dnums.begin(), it) < 4) ? ", ": (it + 1 != dnums.end() ? " [...]" CLR: CLR));
		NEWL;
		PRINT TAB CYN UNDL BOLD "After" CYN BOLD ": ";
		for (std::deque<__uint64_t>::iterator	it = resultdeq.begin(); it != resultdeq.end() && std::distance(resultdeq.begin(), it) < 5; ++it)
			PRINT CYN BOLD AND *it AND ((it + 1 != resultdeq.end() && std::distance(resultdeq.begin(), it) < 4) ? ", ": (it + 1 != resultdeq.end() ? " [...]" CLR: CLR));
		NEWL;
	}
	PmergeMe::_checkIsSorted(resultvec, vnums);
	PmergeMe::_checkIsSorted(resultdeq, dnums);
}

const char	*PmergeMe::InvalidArgException::what() const throw()
{
	return (RED BOLD "There is an invalid argument." CLR);
}
const char	*PmergeMe::SortFailedException::what() const throw()
{
	return (RED BOLD "Somehow the merge sort failed 🤔." CLR);
}
