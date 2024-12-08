/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:11:13 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/08 17:44:12 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <spellBook.hpp>
# include <iostream>

# define FRAG_HP 100
# define FRAG_EP 100
# define FRAG_DMG 30 

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(const FragTrap &trap);
		FragTrap(const std::string &name);
		FragTrap	&operator =(const FragTrap &rhs);
		~FragTrap();
	
		void highFivesGuys();
};

#endif