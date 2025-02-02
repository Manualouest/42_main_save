/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 09:05:52 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/31 14:48:59 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <spellBook.hpp>
#include <stack>
#include <deque>
#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	{
		mstack.push(5);
		mstack.push(17);
		PRINT mstack.top() ENDL;
		mstack.pop();
		PRINT mstack.size() ENDL;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			PRINT *it ENDL;
			++it;
		}
		std::stack<int> s(mstack);
		return 0;
	}
}