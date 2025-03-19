/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:53:08 by mbirou            #+#    #+#             */
/*   Updated: 2025/03/18 15:12:23 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <spellBook.hpp>
#include "easyfind.hpp"

// Sequence containers
#include <vector>
#include <deque>
#include <list>

// Associative containers
#include <set>

int	main()
{
	std::string Str = std::string((char []){(char)1, (char)2, (char)3, (char)4, (char)5, (char)6, (char)7, (char)8, (char)9, (char)0});
	int	Int[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::vector<int> Vec (Int, Int + 9);
	std::deque<int> Deq (Int, Int + 9);
	std::list<int> List (Int, Int + 9);
	std::set<int> Set (Int, Int + 9);
	std::multiset<int> MultiSet (Int, Int + 9);

	PRINT BOLD "Searching for '1' inside the String\t(" AND printContainer(Str) AND "):" TAB CYN BOLD AND easyfind(Str, 1) CENDL;
	PRINT BOLD "Searching for '2' inside the Vector\t(" AND printContainer(Vec) AND "):" TAB CYN BOLD AND easyfind(Vec, 2) CENDL;
	PRINT BOLD "Searching for '3' inside the Deque\t(" AND printContainer(Deq) AND "):" TAB CYN BOLD AND easyfind(Deq, 3) CENDL;
	PRINT BOLD "Searching for '4' inside the List\t(" AND printContainer(List) AND "):" TAB CYN BOLD AND easyfind(List, 4) CENDL;
	PRINT BOLD "Searching for '5' inside the Set\t(" AND printContainer(Set) AND "):" TAB CYN BOLD AND easyfind(Set, 5) CENDL;
	PRINT BOLD "Searching for '6' inside the MultiSet\t(" AND printContainer(MultiSet) AND "): " TAB CYN BOLD AND easyfind(MultiSet, 6) CENDL;
	NEWL;
	PRINT BOLD "Testing errors, should throw an error" CENDL;
	try
	{
		PRINT BOLD "Searching for '42' inside the String\t(" AND printContainer(Str) AND "): " TAB CYN BOLD AND easyfind(Str, 42) CENDL;
	}
	catch (std::exception &e)
	{
		PRINT e.what() CENDL;
	}
	try
	{
		PRINT BOLD "Searching for '42' inside the Deque\t(" AND printContainer(Deq) AND "): " TAB CYN BOLD AND easyfind(Deq, 42) CENDL;
	}
	catch (std::exception &e)
	{
		PRINT e.what() CENDL;
	}
	try
	{
		PRINT BOLD "Searching for '42' inside the MultiSet\t(" AND printContainer(MultiSet) AND "): " TAB CYN BOLD AND easyfind(MultiSet, 42) CENDL;
	}
	catch (std::exception &e)
	{
		PRINT e.what() CENDL;
	}
}
