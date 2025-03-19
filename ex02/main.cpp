/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:05:52 by mbirou            #+#    #+#             */
/*   Updated: 2025/03/18 16:13:49 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <spellBook.hpp>
#include <stack>
#include <deque>
#include <ctime>
#include "MutantStack.hpp"

std::deque<int> deqGen(int len)
{
	std::srand(std::time(NULL));
	std::deque<int>	deque (len, 0);
	int					rNum;
	for (int i = 0; i < len; ++i)
	{
		while (rNum = std::rand(), *std::find(deque.begin(), deque.end(), rNum) == rNum)
			rNum = std::rand();
		deque[i] = rNum;
	}
	return (deque);
}

int main()
{
	std::deque<int> deq = deqGen(10);
	MutantStack<int> mstack;
	{
		
	}
}