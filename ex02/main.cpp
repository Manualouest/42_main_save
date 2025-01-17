/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:59:54 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/17 19:05:08 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <csignal>
#include <spellBook.hpp>

Base *generate(void)
{
	std::srand(std::time(NULL));
	int	baseClass = std::rand() % 3;
	switch (baseClass)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		default :
			return (new C());
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		PRINT CYN BOLD "Our sources say this is an A. 🕴️" CENDL;
	else if (dynamic_cast<B*>(p) != NULL)
		PRINT CYN BOLD "Our sources say this is an B. 🕴️" CENDL;
	else if (dynamic_cast<C*>(p) != NULL)
		PRINT CYN BOLD "Our sources say this is an C. 🕴️" CENDL;
}

void identify(Base& p)
{
	try 
	{
		Base &test = dynamic_cast<A&>(p);
		PRINT CYN BOLD "Our sources say this is an A. 🕴️" CENDL;
	}
	catch (...) {}
	try 
	{
		Base &test = dynamic_cast<B&>(p);
		PRINT CYN BOLD "Our sources say this is an B. 🕴️" CENDL;
	}
	catch (...) {}
	try 
	{
		Base &test = dynamic_cast<C&>(p);
		PRINT CYN BOLD "Our sources say this is an C. 🕴️" CENDL;
	}
	catch (...) {}
}

int	main()
{
	Base *test = generate();
	identify(test);
	identify(*test);
	delete test;
}

