/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:31:29 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/28 19:14:23 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <spellBook.hpp>
# include <iostream>

class ICharacter;

class AMateria
{
	public:
		AMateria();
		AMateria(const AMateria &src);
		AMateria(std::string const & type);
		AMateria	&operator =(const AMateria &rhs);
		virtual ~AMateria();

		// [...];
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected:
		std::string	_type;

};
