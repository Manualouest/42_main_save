/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:41:39 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/08 17:43:56 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <spellBook.hpp>
# include <iostream>

# define SCAV_HP 100
# define SCAV_EP 50
# define SCAV_DMG 20 

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(const ScavTrap &trap);
		ScavTrap(const std::string &name);
		ScavTrap	&operator =(const ScavTrap &rhs);
		~ScavTrap();

		void		attack(const std::string &target);
		void		guardGate();
		void		setGuard(const bool &status);
		const bool	&getGuard() const;
	
	protected:
		bool	_guardStatus;
};

#endif