/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:35:28 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/01 16:31:00 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <string>

class Replace
{
	public:
		Replace(void);
		~Replace(void);
		bool	setup(std::string filename, std::string s1, std::string s2);
		void	execute(void);

	private:
		std::string		_s1;
		std::string		_s2;
		std::ifstream	_ifs;
		std::ofstream	_ofs;
		std::string		_buffLine;
};

#endif