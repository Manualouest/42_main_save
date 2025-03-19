/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:02:16 by mbirou            #+#    #+#             */
/*   Updated: 2025/03/19 11:30:55 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <spellBook.hpp>
#include "Whatever.hpp"

int main( void )
{
	{
		int a = 1;
		int b = 2;
		int c = 3;

		PRINT BOLD "a = " AND a AND ", b = " AND b AND ", c = " AND c CENDL;
		PRINT CYN BOLD "swap a and b" CENDL;
		::swap(a, b);
		PRINT BOLD "a = " AND a AND ", b = " AND b AND ", c = " AND c CENDL;
		PRINT CYN BOLD "swap c and b" CENDL;
		::swap(c, b);
		PRINT BOLD "a = " AND a AND ", b = " AND b AND ", c = " AND c CENDL;
		PRINT CYN BOLD "swap a and b" CENDL;
		::swap(a, b);
		PRINT BOLD "a = " AND a AND ", b = " AND b AND ", c = " AND c CENDL;

		NEWL;
		PRINT BOLD "min(a, b) : " AND ::min(a, b) CENDL;
		PRINT BOLD "min(b, c) : " AND ::min(b, c) CENDL;
		PRINT BOLD "max(c, a) : " AND ::max(c, a) CENDL;
		PRINT BOLD "max(a, b) : " AND ::max(a, b) CENDL;
	}
	{
		NEWL;
		std::string a = "Hello";
		std::string b = "zHEllo";
		std::string c = "ZHEllo";

		PRINT BOLD "a = " AND a AND ", b = " AND b AND ", c = " AND c CENDL;
		PRINT CYN BOLD "swap a and b" CENDL;
		::swap(a, b);
		PRINT BOLD "a = " AND a AND ", b = " AND b AND ", c = " AND c CENDL;
		PRINT CYN BOLD "swap c and b" CENDL;
		::swap(c, b);
		PRINT BOLD "a = " AND a AND ", b = " AND b AND ", c = " AND c CENDL;
		PRINT CYN BOLD "swap a and b" CENDL;
		::swap(a, b);
		PRINT BOLD "a = " AND a AND ", b = " AND b AND ", c = " AND c CENDL;

		NEWL;
		PRINT BOLD "min(a, b) : " AND ::min(a, b) CENDL;
		PRINT BOLD "min(b, c) : " AND ::min(b, c) CENDL;
		PRINT BOLD "max(c, a) : " AND ::max(c, a) CENDL;
		PRINT BOLD "max(a, b) : " AND ::max(a, b) CENDL;
	}
}
