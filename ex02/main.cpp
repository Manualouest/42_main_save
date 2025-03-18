/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:37:03 by mbirou            #+#    #+#             */
/*   Updated: 2025/03/18 14:54:02 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <spellBook.hpp>
#include "Array.hpp"
#include <Whatever.hpp>

int	main()
{
	Array<char> a(26);
	Array<int> t(10);
	PRINT BOLD "creation of two empty Arrays;" ENDL AND "char:" TAB AND a ENDL AND BOLD "int:" TAB AND t CENDL;
	{
		NEWL;
		for (int i = 0; i < t.size(); ++i)
			t[i] = i;
		for (int i = 0; i < a.size(); ++i)
			a[i] = i + 'a';
		PRINT BOLD "filling both of them;" ENDL AND "char:" TAB AND a ENDL AND BOLD "int:" TAB AND t CENDL;
	}
	{
		NEWL;
		for (int i = 0; i < a.size() / 2; ++i)
			swap(a[i], a[a.size() - i - 1]);
		for (int i = 0; i < t.size() / 2; ++i)
			swap(t[i], t[t.size() - i - 1]);
		PRINT BOLD "reversing both of them;" ENDL AND "char:" TAB AND a ENDL AND BOLD "int:" TAB AND t CENDL;
	}
	{
		NEWL;
		PRINT BOLD "testing the exceptions;" CENDL;
		try
		{
			PRINT BOLD "a[-1]:" TAB;
			a[-1] = 'a';
		}
		catch (std::exception &e)
		{
			PRINT e.what();
		}
		try
		{
			PRINT BOLD "a[26]:" TAB;
			a[26] = 'z';
		}
		catch (std::exception &e)
		{
			PRINT e.what();
		}
	}
	{
		NEWL;
		PRINT BOLD "testing copy:" CENDL;
		Array<int>	d(11);
		for (int i = 0; i < d.size(); ++i)
			d[i] = i;
		PRINT BOLD "d before: " AND d CENDL;
		PRINT BOLD "d = t" CENDL;
		d = t;
		PRINT BOLD "d after:  " AND d CENDL ENDL;
		PRINT BOLD "testing if d can modify t (d[0] = 42):" CENDL;
		d[0] = 42;
		PRINT BOLD "d: " AND d ENDL AND BOLD "t: " AND t CENDL;
	}
}