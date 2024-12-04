/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:48:59 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/04 11:48:33 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	public:
		Harl(void);
		~Harl(void);
		void	complain(const std::string &level);

	private:
		void		debug(void) const;
		void		info(void) const;
		void		warning(void) const;
		void		error(void) const;
		std::string	_levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
		void		(Harl::*_complains[4])(void) const = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
};

#endif