/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:10:54 by mbirou            #+#    #+#             */
/*   Updated: 2025/03/21 13:17:38 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::ifstream					BitcoinExchange::_input;
std::map<int, double>			BitcoinExchange::_database;
std::map<std::string, double>	BitcoinExchange::_inputData;

int	convertDate(const std::string &line, const bool &isData)
{
	int	ypos = line.find('-');
	int	mpos = line.substr(line.find('-') + 1).find('-');
	int	dpos;
	if (isData)
		dpos = line.find(',') - ypos - mpos - 2;
	else
		dpos = line.find(" :") - ypos - mpos - 2;
	if (ypos == 0 || mpos == 0 || dpos == 0)
		return (-1);
	int	y = std::atoi(line.substr(0, ypos).c_str());
	int	m = std::atoi(line.substr(ypos + 1, mpos).c_str());
	int	d = std::atoi(line.substr(ypos + mpos + 2, dpos).c_str());
	if (m <= 0 || m > 12 || y < 0 || y > 9999 || d <= 0
		|| (d > 30 && (m == 4 || m == 6 || m == 9 || m == 11))
		|| (d > 31 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
		|| (d > 28 && m == 2 && !(!(y % 4) && (y % 100 || !(y % 400))))
		|| (d > 29 && m == 2 && !(y % 4) && (y % 100 || !(y % 400))))
		return (-1);
	return (y * 10000 + m * 100 + d);
}

std::string	formatString(std::string str, const int &prevLen, const bool &isFirst)
{
	
	if (isFirst)
	{
		str.replace(str.find('|'), 1, ":");
		return (str);
	}
	str.insert(0, prevLen, ' ');
	return (str);
}

std::string	itostr(const int &nb, const bool &needBig)
{
	std::string	str;

	for (int i = nb; i > 0; i /= 10)
		str.insert(0, 1, static_cast<char>((int)i % 10 + '0'));
	if (needBig)
	{
		str.insert(0, 1, '1');
		str.insert(1, 19 - str.length(), '0');
	}
	return (str);
}

int	BitcoinExchange::_getClosestDate(const int &date)
{
	if (_database.lower_bound(date)->first == date)
		return (date);
	return ((--_database.lower_bound(date))->first);
}

void	BitcoinExchange::getRates(const std::string &filename)
{
	std::string	line;
	int			date;
	double		value;
	bool		sawHead = false;
	std::size_t	maxLen;

	_input.open(filename.c_str(), std::ifstream::in);
	if (_input.fail())
		throw(BitcoinExchange::CannotOpenInputFileException());
	_setupDatabase();

	while (std::getline(_input, line))
	{
		if (line == "date | value")
		{
			if (!sawHead && _inputData.size() == 0)
				sawHead = true;
			else
				_inputData.insert(std::pair<std::string, double>(line.insert(0, itostr(_inputData.size(), true)), -1));
			continue ;
		}
		if (!sawHead)
			_inputData.insert(std::pair<std::string, double>(line.insert(0, itostr(_inputData.size(), true)), -3));
		else if (line.find_first_not_of("0123456789-.| ") != std::string::npos
			|| line.find('|') != line.rfind('|') || line.find('|') == std::string::npos
			|| line.find('.') != line.rfind('.')
			|| line.find('-') == std::string::npos
			|| line.substr(line.find('-') + 1).find('-') == std::string::npos
			|| line.substr(line.substr(line.find('-') + 1).find('-') + line.find('-') + 2).find('-') != std::string::npos)
			_inputData.insert(std::pair<std::string, double>(line.insert(0, itostr(_inputData.size(), true)), -2));
		else
		{
			date = convertDate(line, true);
			value = std::strtod(line.substr(line.find("| ") + 1).c_str(), NULL);
			if (date == -1)
				_inputData.insert(std::pair<std::string, double>(line.insert(0, itostr(_inputData.size(), true)), -4));
			else if (value < 0 || value > 1000 || errno == ERANGE)
				_inputData.insert(std::pair<std::string, double>(line.insert(0, itostr(_inputData.size(), true)), -5));
			else
				_inputData.insert(std::pair<std::string, double>(formatString(line.insert(0, itostr(_inputData.size(), true)), 0, true), value));
		}
	}
	maxLen = 0;
	for (std::map<std::string, double>::iterator it = _inputData.begin(); it != _inputData.end(); ++it)
	{
		if (it->first.length() > maxLen)
			maxLen = it->first.length();
	}
	for (std::map<std::string, double>::iterator it = _inputData.begin(); it != _inputData.end(); ++it)
	{
		PRINT BOLD AND it->first.substr(19, it->first.length()) AND CLR;
		switch ((int)it->second)
		{
		case (-1):
			PRINT (std::string(" ").insert(0, maxLen - it->first.length(), ' ')) AND RED BOLD AND "-> Header not at start ??" CENDL;
			break;
		case (-2):
			PRINT (std::string(" ").insert(0, maxLen - it->first.length(), ' ')) AND RED BOLD AND "-> Line is invalid :(" CENDL;
			break;
		case (-3):
			PRINT  (std::string(" ").insert(0, maxLen - it->first.length(), ' ')) AND RED BOLD AND "-> Missing header line at start >:[" CENDL;
			break;
		case (-4):
			PRINT (std::string(" ").insert(0, maxLen - it->first.length(), ' ')) AND RED BOLD AND "-> Date seems to be invalid :/" CENDL;
			break;
		case (-5):
			PRINT (std::string(" ").insert(0, maxLen - it->first.length(), ' ')) AND RED BOLD AND "-> This isn't a valid value :\\" CENDL;
			break;
		default:
			PRINT (std::string(" ").insert(0, maxLen - it->first.length(), ' ')) AND CYN BOLD AND "-> " AND std::setprecision(10) AND (it->second * _database.find(_getClosestDate(convertDate(it->first.substr(19, it->first.length()), false)))->second) CENDL;
			break;
		}
	}
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
	while (std::getline(data, line))
	{
		if (line == "date,exchange_rate")
		{
			if (!sawHead)
				sawHead = true;
			else
				throw(BitcoinExchange::BadDatabaseException(line, itostr(_database.size() + 1 + sawHead, false)));
			continue ;
		}
		if (!sawHead
			|| line.find_first_not_of("0123456789-.,") != std::string::npos
			|| line.find(',') != line.rfind(',') || line.find(',') == std::string::npos
			|| line.find(',') == line.length() - 1 || (line.find('.') == line.length() - 1 && line[line.find('.') - 1] == ',')
			|| line.find('.') != line.rfind('.')
			|| line.find('-') == std::string::npos
			|| line.substr(line.find('-') + 1).find('-') == std::string::npos
			|| line.substr(line.substr(line.find('-') + 1).find('-') + line.find('-') + 2).find('-') != std::string::npos)
			throw(BitcoinExchange::BadDatabaseException(line, itostr(_database.size() + 1 + sawHead, false)));
		date = convertDate(line, true);
		value = std::strtod(line.substr(line.find(',') + 1).c_str(), NULL);
		if (date == -1 || value < 0 || errno == ERANGE
			|| _database.find(date) != _database.end())
			throw(BitcoinExchange::BadDatabaseException(line, itostr(_database.size() + 1 + sawHead, false)));
		_database.insert(std::pair<int, double>(date, value));
	}
	if (!_database.size())
		throw(BitcoinExchange::BadDatabaseException("file is empty", "0"));
}

const char	*BitcoinExchange::CannotOpenDatabaseException::what() const throw()
{
	return (RED BOLD UNDL "Error" RED BOLD " Database could not be opened" CLR);
}

BitcoinExchange::BadDatabaseException::BadDatabaseException(std::string line, const std::string &nbLine)
{
	_msg = std::string(RED BOLD UNDL "Error" RED BOLD " Database is invalid at line ") + nbLine + ": '" + line + "'" CLR;

	if (line.empty())
		_msg.insert(_msg.length(), RED BOLD " line is empty" CLR);
	else if (line == "file is empty")
		;
	else if (nbLine == "1")
		_msg.insert(_msg.length(), RED BOLD " != date,exchange_rate" CLR);
	else if (line.find_first_not_of("0123456789-.,") != std::string::npos)
	{
		_msg.insert(_msg.length() - (line.length() - line.find_last_not_of("0123456789-.,")) - 4, RED BOLD);
		_msg.insert(_msg.length() - 16 - (line.length() - line.find_first_not_of("0123456789-.,")), RED BOLD DUNDL);
		_msg.insert(_msg.length() - 4, " [" + line.substr(line.find_first_not_of("0123456789-.,"), line.find_last_not_of("0123456789-.,") - line.find_first_not_of("0123456789-.,") + 1) + "] should not be there");
	}
	else if (line.find(',') != line.rfind(',') && line.find(',') != std::string::npos)
	{
		_msg.insert(_msg.length() - (line.length() - (line.substr(line.find(',') + 1).find(',') + line.find(','))) - 3, RED BOLD);
		_msg.insert(_msg.length() - 15 - (line.length() - (line.substr(line.find(',') + 1).find(',') + line.find(','))), RED BOLD DUNDL);
		_msg.insert(_msg.length() - 4, " [" + line.substr(line.substr(line.find(',') + 1).find(',') + line.find(',') + 1, 1) + "] should not be there");
	}
	else if (line.find(',') == std::string::npos)
		_msg.insert(_msg.length() - 4, " missing ',' between date and exchange_rate");
	else if (line.find('.') != line.rfind('.') && line.find('.') != std::string::npos)
	{
		_msg.insert(_msg.length() - (line.length() - (line.substr(line.find('.') + 1).find('.') + line.find('.'))) - 3, RED BOLD);
		_msg.insert(_msg.length() - 15 - (line.length() - (line.substr(line.find('.') + 1).find('.') + line.find('.'))), RED BOLD DUNDL);
		_msg.insert(_msg.length() - 4, " [" + line.substr(line.substr(line.find('.') + 1).find('.') + line.find('.') + 1, 1) + "] should not be there");
	}
	else if (line.find('-') == std::string::npos
			|| line.substr(line.find('-') + 1).find('-') == std::string::npos)
		_msg.insert(_msg.length() - 4, " missing a '-' to make a valid date");
	else if (line.substr(line.substr(line.find('-') + 1).find('-') + line.find('-') + 2).find('-') != std::string::npos)
	{
		_msg.insert(_msg.length() - (line.length() - (line.substr(line.substr(line.find('-') + 1).find('-') + line.find('-') + 2).find('-') + line.find('-'))), RED BOLD);
		_msg.insert(_msg.length() - 12 - (line.length() - (line.substr(line.substr(line.find('-') + 1).find('-') + line.find('-') + 2).find('-') + line.find('-'))), RED BOLD DUNDL);
		_msg.insert(_msg.length() - 4, " [" + line.substr(line.substr(line.substr(line.find('-') + 1).find('-') + line.find('-') + 2).find('-') + line.find('-') + 4, 1) + "] should not be there");
	}
	else if (convertDate(line, true) == -1)
	{
		_msg.insert(_msg.length() - (line.length() - line.find(",") + 1) - 4, RED BOLD);
		_msg.insert(_msg.length() - 16 - line.length(), RED BOLD DUNDL);
		_msg.insert(_msg.length() - 4, " [" + line.substr(0, line.find(",")) + "] this date is invalid");
	}
	else if (std::strtod(line.substr(line.find(',') + 1).c_str(), NULL) < 0 || errno == ERANGE)
	{
		_msg.insert(_msg.length() - 5, RED BOLD);
		_msg.insert(_msg.length() - 16 - (line.length() - line.find(",") - 1), RED BOLD DUNDL);
		_msg.insert(_msg.length() - 4, " [" + line.substr(line.find(",") + 1, line.length()) + "] this number is invalid");
	}
	else if (line.find(',') == line.length() - 1 || (line.find('.') == line.length() - 1 && line[line.find('.') - 1] == ','))
		_msg.insert(_msg.length() - 4, " [] missing number");
}

const char	*BitcoinExchange::BadDatabaseException::what() const throw()
{
	if (!_msg.empty())
		return (_msg.c_str());
	return (RED BOLD UNDL "Error" RED BOLD " Database is invalid" CLR);
}

const char	*BitcoinExchange::CannotOpenInputFileException::what() const throw()
{
	return (RED BOLD UNDL "Error" RED BOLD " Input file could not be opened" CLR);
}
