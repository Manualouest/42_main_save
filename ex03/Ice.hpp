/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:51:25 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/13 12:58:11 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <spellBook.hpp>
# include <iostream>

class Ice: public AMateria
{
	public:
		Ice();
		Ice(const Ice &src);
		Ice(const std::string &type);
		Ice	&operator =(const Ice &rhs);
		~Ice();

		const std::string	&getType() const;
		AMateria			*clone() const;
		void				use(ICharacter &target);
};

#endif