/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:48:59 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/04 12:30:43 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

#define HARL_FALLTHROUGH __attribute__ ((fallthrough))

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
};

#endif