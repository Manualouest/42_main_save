/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:38:53 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/03 18:39:34 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"

Sed::Sed(void)
{
	this->_s1 = "";
	this->_s2 = "";
}

Sed::~Sed(void)
{
	if(this->_ifs.is_open())
		this->_ifs.close();
	if(this->_ofs.is_open())
		this->_ofs.close();
}

bool	Sed::setup(std::string filename, std::string s1, std::string s2)
{
	this->_ifs.open(filename.c_str(), std::ifstream::in);
	if (!this->_ifs.fail())
		this->_ofs.open(filename.append(".replace").c_str(), std::ofstream::out | std::ofstream::trunc);
	if (this->_ifs.fail() || this->_ofs.fail())
	{
		std::cout << "\033[31;1mCould not open file\033[0m 😿" << std::endl;
		return (false);
	}
	this->_s1 = s1;
	this->_s2 = s2;
	return (true);
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
