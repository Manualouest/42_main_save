/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:10:08 by mbirou            #+#    #+#             */
/*   Updated: 2025/02/04 17:02:45 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <exception>
#include <fstream>
#include <cstdlib>
#include <cerrno>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <spellBook.hpp>

class	BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange(const std::string &filename);
		BitcoinExchange	&operator =(const BitcoinExchange &rhs);
		~BitcoinExchange();		
	
		void	getRates();

	private:
		std::ifstream						_input;
		std::map<int, double>				_database;
		std::map<std::string, double>		_inputData;

		void	_setupDatabase();
		int		_getClosestDate(const int &date);
		// int		_convertDate(const std::string &line, bool isData) const;

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
