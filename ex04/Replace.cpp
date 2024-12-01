/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:38:53 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/01 16:07:08 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(void)
{
	this->_s1 = "";
	this->_s2 = "";
}

Replace::~Replace(void)
{
	this->_ifs.close();
	this->_ofs.close();
}

bool	Replace::setup(std::string filename, std::string s1, std::string s2)
{
	this->_ifs.open(filename.c_str(), std::ifstream::in);
	if (!this->_ifs.fail())
		this->_ofs.open(filename.append(".replace").c_str(), std::ofstream::out | std::ofstream::trunc);
	if (this->_ifs.fail() || this->_ofs.fail())
	{
		std::cout << "\033[31;1mCould not open file\033[0m 😿" << std::endl;
		this->~Replace();
		return (false);
	}
	this->_s1 = s1;
	this->_s2 = s2;
	return (true);
}

void	Replace::execute(void)
{
	size_t pos;

	while (getline(this->_ifs, this->_buffLine))
	{
		pos = 0;
		for (pos = this->_buffLine.find(this->_s1, pos); pos != std::string::npos; pos = this->_buffLine.find(this->_s1, pos))
		{

			this->_buffLine.erase(pos, this->_s1.length());
			this->_buffLine.insert(pos, this->_s2);
			pos += this->_s2.length();
		}
		this->_ofs << this->_buffLine << std::endl;
	}
}
