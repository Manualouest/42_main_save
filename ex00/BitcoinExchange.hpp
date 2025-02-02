/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:10:08 by mbirou            #+#    #+#             */
/*   Updated: 2025/02/03 00:09:13 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <map>
#include <exception>
#include <fstream>
#include <cstdlib>
#include <cerrno>
#include <cstdlib>
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
	
		void	getRates() const;

	private:
		std::ifstream			_input;
		std::map<int, double>	_database;

		void	_setupDatabase();
		int		_convertDate(const std::string &date) const;

	class	CannotOpenDatabaseException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class	BadDatabaseException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class	CannotOpenInputFileException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
};
