/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sed.hpp                	                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 12:35:28 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/03 18:38:51 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <fstream>
#include <string>

class Sed
{
	public:
		Sed(void);
		~Sed(void);
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