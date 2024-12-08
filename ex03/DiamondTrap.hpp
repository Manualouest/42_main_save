/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:23:30 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/08 17:46:59 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <spellBook.hpp>
# include <iostream>

# define DIAMOND_HP FRAG_HP
# define DIAMOND_EP SCAV_EP
# define DIAMOND_DMG FRAG_DMG

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap &trap);
		DiamondTrap(const std::string &name);
		DiamondTrap	&operator =(const DiamondTrap &rhs);
		~DiamondTrap();

		virtual void	attack(const std::string &target);
		void			whoAmI();

	private:
		std::string _name;
};

#endif