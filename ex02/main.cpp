/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:13:40 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/21 10:20:26 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>
#include <spellBook.hpp>
#include "MutantStack.hpp"

int	main()
{
	// {
	// 	MutantStack<int> mstack;
	// 	mstack.push(5);
	// 	mstack.push(17);
	// 	std::cout << mstack.top() << std::endl;
	// 	mstack.pop();
	// 	std::cout << mstack.size() << std::endl;
	// 	mstack.push(3);
	// 	mstack.push(5);
	// 	mstack.push(737);
	// 	//[...]
	// 	mstack.push(0);
	// 	MutantStack<int>::iterator it = mstack.begin();
	// 	MutantStack<int>::iterator ite = mstack.end();
	// 	++it;
	// 	--it;
	// 	while (it != ite)
	// 	{
			// std::cout << *it << std::endl;
			// ++it;
	// 	}
	// 	std::stack<int> s(mstack);
	// }
	NEWL;
	{
		std::stack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		for (int i = 0; i < mstack.size(); ++i)
		{
			PRINT mstack.top() ENDL;
			mstack.pop();
		}
		std::stack<int> s(mstack);
	}
}