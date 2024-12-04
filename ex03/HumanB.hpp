/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 19:01:10 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/04 12:33:40 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(const std::string &name);
		~HumanB(void);
		void	setWeapon(Weapon &weapon);
		void	attack(void) const;
	
	private:
		Weapon		*_weapon;
		std::string	_name;
};

#endif