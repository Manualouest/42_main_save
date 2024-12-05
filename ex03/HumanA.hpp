/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:01:05 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/04 12:33:42 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	public:
		HumanA(const std::string &name, Weapon &weapon);
		~HumanA(void);
		void	attack(void) const;
	
	private:
		Weapon		&_weapon;
		std::string	_name;
};

#endif