/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:40:24 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/07 18:34:42 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <spellbook.hpp>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const ClapTrap &trap);
		ClapTrap(const std::string &name);
		ClapTrap	&operator =(const ClapTrap &rhs);
		~ClapTrap();

		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		const std::string	&getName() const;
		void				setName(const std::string &name);
		const unsigned int	&getDmg() const;
		void				setDmg(const unsigned int &dmg);
		const unsigned int	&getHp() const;
		void				setHp(const unsigned int &hp);
		const unsigned int	&getEnergy() const;
		void				setEnergy(const unsigned int &energy);

	protected:
		std::string		_name;
		unsigned int	_hp;
		unsigned int	_energy;
		unsigned int	_dmg;
};

#endif