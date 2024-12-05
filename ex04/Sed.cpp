/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:38:53 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/04 12:24:52 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(const std::string &filename, const std::string &s1, const std::string &s2)
{
	std::string	outfile;

	if (filename.empty())
		throw (std::string("\033[31;1mFilename is empty 😾\033[0m"));
	if (s1.empty())
		throw (std::string("\033[31;1mString to search is empty 😾\033[0m"));
	if (s2.empty())
		throw (std::string("\033[31;1mString for replace is empty 😾\033[0m"));
	outfile = filename;
	this->_ifs.open(filename.c_str(), std::ifstream::in);
	if (!this->_ifs.fail())
		this->_ofs.open(outfile.append(".replace").c_str(), std::ofstream::out | std::ofstream::trunc);
	if (this->_ifs.fail() || this->_ofs.fail())
		throw (std::string("\033[31;1mCould not open file\033[0m 😿"));
	this->_s1 = s1;
	this->_s2 = s2;
}

Sed::~Sed(void)
{
	if(this->_ifs.is_open())
		this->_ifs.close();
	if(this->_ofs.is_open())
		this->_ofs.close();
}


void	Sed::execute(void)
{
	size_t pos;

	while (getline(this->_ifs, this->_buffLine))
	{
		pos = 0;
		for (pos = this->_buffLine.find(this->_s1, pos);
			pos != std::string::npos; pos = this->_buffLine.find(this->_s1, pos))
		{

			this->_buffLine.erase(pos, this->_s1.length());
			this->_buffLine.insert(pos, this->_s2);
			pos += this->_s2.length();
		}
		this->_ofs << this->_buffLine << std::endl;
	}
}
