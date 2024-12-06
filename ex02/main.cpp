/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:50:51 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/06 15:23:28 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main()
{
	Fixed a = 15;
	Fixed b = 1.5f;
	Fixed c = a;

	std::cout << "\033[36;1m";
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	{
		std::cout << "a > b: " << (a > b) << std::endl;
		std::cout << "a > c: " << (a > c) << std::endl;
		std::cout << "a < b: " << (a < b) << std::endl;
		std::cout << "a < c: " << (a < c) << std::endl;
		std::cout << "a >= b: " << (a >= b) << std::endl;
		std::cout << "a >= c: " << (a >= c) << std::endl;
		std::cout << "a <= b: " << (a <= b) << std::endl;
		std::cout << "a <= c: " << (a <= c) << std::endl;
		std::cout << "a == b: " << (a == b) << std::endl;
		std::cout << "a == c: " << (a == c) << std::endl;
		std::cout << "a != b: " << (a != b) << std::endl;
		std::cout << "a != c: " << (a != c) << std::endl;
	} // Relational Operators
	std::cout << std::endl;
	{
		std::cout << "a + b = " << a + b << std::endl;
		std::cout << "a - b = " << a - b << std::endl;
		std::cout << "a * b = " << a * b << std::endl;
		std::cout << "a / b = " << a / b << std::endl;
	} // Arithmetic Operators
	std::cout << std::endl;
	{
		std::cout << "a; a++; a > " << a << " " << a++ << " " << a << std::endl;
		std::cout << "a; ++a; a > " << a << " " << ++a << " " << a << std::endl;
		std::cout << "a; a--; a > " << a << " " << a-- << " " << a << std::endl;
		std::cout << "a; --a; a > " << a << " " << --a << " " << a << std::endl;
	} // Incremental / Decremental Operators
	std::cout << std::endl;
	{
		std::cout << "min(a, b) = " << Fixed::min(a, b) << std::endl;
		std::cout << "max(a, b) = " << Fixed::max(a, b) << std::endl;
	} // Static Methods
	std::cout << "\033[0m";
}
