/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:05:52 by mbirou            #+#    #+#             */
/*   Updated: 2025/03/20 11:00:16 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "MutantStack.hpp"
#include <spellBook.hpp>
#include <stack>
#include <deque>
#include <ctime>
#include <algorithm>
#include <easyfind.hpp>

std::deque<int> deqGen(int len)
{
	std::srand(std::time(NULL));
	std::deque<int>	deque (len, 0);
	int					rNum;
	for (int i = 0; i < len; ++i)
	{
		while (rNum = std::rand() % 900 + 100, *std::find(deque.begin(), deque.end(), rNum) == rNum)
			;
		deque[i] = rNum;
	}
	return (deque);
}

int main()
{
	std::deque<int> deq = deqGen(15);
	MutantStack<int> mstack1((std::stack<int>(deq)));
	MutantStack<int> mstack2(mstack1);
	PRINT BOLD "mstack1: " AND printContainer(mstack1) CENDL;
	PRINT BOLD "mstack2: " AND printContainer(mstack2) CENDL;
	NEWL;
	{
		PRINT BOLD "trying easyfind on mstack1:" CENDL;
		int tpIndex = std::rand() % 15;
		PRINT TAB BOLD "looking for " AND deq[tpIndex] AND ":" TAB CYN BOLD AND *easyfind(mstack1, deq[tpIndex]) CENDL;
		tpIndex = std::rand() % 15;
		PRINT TAB BOLD "looking for " AND deq[tpIndex] AND ":" TAB CYN BOLD AND *easyfind(mstack1, deq[tpIndex]) CENDL;
		tpIndex = std::rand() % 15;
		PRINT TAB BOLD "looking for " AND deq[tpIndex] AND ":" TAB CYN BOLD AND *easyfind(mstack1, deq[tpIndex]) CENDL;
		tpIndex = std::rand() % 15;
		PRINT TAB BOLD "looking for " AND deq[tpIndex] AND ":" TAB CYN BOLD AND *easyfind(mstack1, deq[tpIndex]) CENDL;
		try
		{
			PRINT TAB BOLD "looking for 1001:" TAB AND *easyfind(mstack1, 1001) CENDL;
		}
		catch(const std::exception& e)
		{
			PRINT e.what() CENDL;
		}
	}
	NEWL;
	{
		PRINT BOLD "trying to edit the stack:" CENDL;
		PRINT TAB BOLD "Changing the first number to 42 and dividing by 2 the others on mstack1:" CENDL;
		NEWL;
		*mstack1.begin() = 42;
		for (MutantStack<int>::iterator	it = mstack1.begin() + 1; it != mstack1.end(); ++it)
			*it /= 2;
		PRINT TAB BOLD "mstack1: " AND printContainer(mstack1) CENDL;
		PRINT TAB BOLD "mstack2: " AND printContainer(mstack2) CENDL;
	}
	NEWL;
	PRINT "**reset of mstack1**" CENDL;
	mstack1 = mstack2;
	NEWL;
	{
		PRINT BOLD "trying the base stack methods:" CENDL;
		NEWL;
		PRINT TAB BOLD "top:" CENDL;
		PRINT TAB TAB BOLD "top of mstack1: " CYN BOLD AND mstack1.top() CENDL;
		PRINT TAB TAB BOLD "top of mstack2: " CYN BOLD AND mstack2.top() CENDL;
		NEWL;
		PRINT TAB BOLD "empty:" CENDL;
		PRINT TAB TAB BOLD "is mstack1 empty? " CYN BOLD AND (mstack1.empty() ? "true" : "false") CENDL;
		PRINT TAB TAB BOLD "is mstack2 empty? " CYN BOLD AND (mstack2.empty() ? "true" : "false") CENDL;
		NEWL;
		PRINT TAB BOLD "size:" CENDL;
		PRINT TAB TAB BOLD "what size if mstack1? " CYN BOLD AND mstack1.size() CENDL;
		PRINT TAB TAB BOLD "what size if mstack2? " CYN BOLD AND mstack2.size() CENDL;
		NEWL;
		PRINT TAB BOLD "push:" CENDL;
		int tpRand = std::rand() % 900 + 100;
		PRINT TAB TAB BOLD "pushing " AND tpRand AND " mstack1" CENDL;
		mstack1.push(tpRand);
		tpRand = std::rand() % 900 + 100;
		PRINT TAB TAB BOLD "pushing " AND tpRand AND " mstack2" CENDL;
		mstack2.push(tpRand);
		PRINT TAB TAB BOLD "mstack1: " AND printContainer(mstack1) CENDL;
		PRINT TAB TAB BOLD "mstack2: " AND printContainer(mstack2) CENDL;
		NEWL;
		PRINT TAB BOLD "pop:" CENDL;
		PRINT TAB TAB BOLD "doing pop on mstack1" CENDL;
		mstack1.pop();
		PRINT TAB TAB BOLD "doing pop on mstack2" CENDL;
		mstack2.pop();
		PRINT TAB TAB BOLD "mstack1: " AND printContainer(mstack1) CENDL;
		PRINT TAB TAB BOLD "mstack2: " AND printContainer(mstack2) CENDL;
		NEWL;
		PRINT TAB BOLD "operator ==:" CENDL;
		PRINT TAB TAB BOLD "are mstack1 and mstack2 equal? " CYN BOLD AND (mstack1 == mstack2 ? "true" : "false") CENDL;
		NEWL;
	}
}