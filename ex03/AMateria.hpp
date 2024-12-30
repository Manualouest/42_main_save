/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:31:29 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/30 15:50:33 by mbirou           ###   ########.fr       */
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

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

	protected:
		std::string	_type;

};
