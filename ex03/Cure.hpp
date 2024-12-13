/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:57:46 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/13 14:12:52 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <spellBook.hpp>
# include <iostream>

class Cure: public AMateria
{
	public:
		Cure();
		Cure(const Cure &src);
		Cure(const std::string &type);
		Cure	&operator =(const Cure &rhs);
		~Cure();

		const std::string	&getType() const;
		AMateria			*clone() const;
		void				use(ICharacter &target);
};

#endif
