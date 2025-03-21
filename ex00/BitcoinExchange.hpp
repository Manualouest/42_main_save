/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:10:08 by mbirou            #+#    #+#             */
/*   Updated: 2025/03/21 14:31:05 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <spellBook.hpp>

class	BitcoinExchange
{
	public:
		static void	getRates(const std::string &filename);

	private:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange	&operator =(const BitcoinExchange &rhs);
		~BitcoinExchange();

		static std::ifstream					_input;
		static std::map<int, double>			_database;
		static std::map<std::string, double>	_inputData;

		static void	_setupDatabase();
		static int	_getClosestDate(const int &date);

	class	CannotOpenDatabaseException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class	BadDatabaseException : public std::exception
	{
		public:
			BadDatabaseException(std::string line, const std::string &nbLine);
			virtual ~BadDatabaseException() throw() {}
			virtual const char	*what() const throw();
		private:
			std::string	_msg;
	};

	class	CannotOpenInputFileException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
};
