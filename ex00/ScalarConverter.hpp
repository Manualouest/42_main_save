/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:49:38 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/17 17:59:27 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <cstdlib>
# include <climits>
# include <cmath>
# include <cerrno>
# include <iostream>
# include <spellBook.hpp>

class ScalarConverter
{
	public:
		static void	convert(const std::string &param);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator =(const ScalarConverter &rhs);
		~ScalarConverter();
		static void	printChar(const std::string &param);
		static void	printInt(const std::string &param);
		static void	printFloat(const std::string &param);
		static void	printDouble(const std::string &param);
};