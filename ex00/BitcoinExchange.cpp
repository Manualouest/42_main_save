/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:10:54 by mbirou            #+#    #+#             */
/*   Updated: 2025/02/03 00:57:56 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	throw(BitcoinExchange::CannotOpenInputFileException());
}

BitcoinExchange::BitcoinExchange(const std::string &filename)
{
	_input.open(filename.c_str(), std::ifstream::in);
	if (_input.fail())
		throw(BitcoinExchange::CannotOpenInputFileException());
	_setupDatabase();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange	&BitcoinExchange::operator =(const BitcoinExchange &rhs)
{
	if (this != &rhs)
	{
		_database.clear();
		_database.insert(rhs._database.begin(), rhs._database.end());
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}	
	
void	BitcoinExchange::getRates() const
{
	;
}

int	BitcoinExchange::_convertDate(const std::string &date) const
{
	if (date.length() < 8)
		return (-1);
	int	y = std::atoi(date.substr(0, 3).c_str());
	int	m = std::atoi(date.substr(5, 7).c_str());
	int	d = std::atoi(date.substr(8, 9).c_str());
	if (m < 0 || m > 12 || y < -9999 || y > 9999 || d < 0
		|| (d > 30 && (m == 4 || m == 6 || m == 9 || m == 11))
		|| (d > 31 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
		|| (d > 28 && m == 2 && !(!(y % 4) && (y % 100 || !(y % 400))))
		|| (d > 29 && m == 2 && !(y % 4) && (y % 100 || !(y % 400))))
		return (-1);
	return (y * 1000 + m * 100 + d);
}

void	BitcoinExchange::_setupDatabase()
{
	std::string		line;
	int				date;
	double			value;
	bool			sawHead = false;
	std::ifstream	data;

	data.open("data.csv", std::ifstream::in);
	if (data.fail())
		throw(BitcoinExchange::CannotOpenDatabaseException());
	do
	{
		std::getline(data, line);
		PRINT line AND "---";
		if (line == "date,exchange_rate" || line == "\n")
		{
			if (!sawHead || (line == "\n" && sawHead))
				sawHead = !sawHead;
			else
				throw(BitcoinExchange::BadDatabaseException());
			PRINT "" ENDL;
			continue;
		}
		PRINT "1";
		if (!sawHead
			|| line.find_first_not_of("0123456789-.,") != std::string::npos
			|| line.find(',') != line.rfind(',') || line.find(',') == std::string::npos
			|| line.find('.') != line.rfind('.')
			|| line.find('-') == std::string::npos
			|| line.substr(line.find('-'), line.length()).find('-') == std::string::npos
			|| line.substr(line.substr(line.find('-'), line.length()).find('-')).find('-') == std::string::npos)
			throw(BitcoinExchange::BadDatabaseException());
		PRINT "2";
		date = _convertDate(line);
		value = std::strtod(line.substr(line.find(','), line.length()).c_str(), NULL);
		if (date == -1
			|| value < 0 || value > 1000 || errno == ERANGE)
			throw(BitcoinExchange::BadDatabaseException());
		PRINT "3" ENDL;
		_database.insert(std::pair<int, float>(date, value));
	}
	while (!line.empty());
	for (std::map<int, double>::iterator it = _database.begin(); it != _database.end(); ++it)
		PRINT BOLD "date: " AND it->first AND "value: " AND it->second CENDL;
}

const char	*BitcoinExchange::CannotOpenDatabaseException::what() const throw()
{
	return (RED BOLD UNDL "Error" RED BOLD " Database could not be opened" CLR);
}

const char	*BitcoinExchange::BadDatabaseException::what() const throw()
{
	return (RED BOLD UNDL "Error" RED BOLD " Database is invalid" CLR);
}

const char	*BitcoinExchange::CannotOpenInputFileException::what() const throw()
{
	return (RED BOLD UNDL "Error" RED BOLD " Input file could not be opened" CLR);
}
