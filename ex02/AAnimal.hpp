/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:40:32 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/11 17:24:49 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <spellBook.hpp>
#include <iostream>

class AAnimal
{
	public:
		AAnimal();
		AAnimal(const AAnimal &src);
		AAnimal	&operator =(const AAnimal &rhs);
		virtual ~AAnimal();
	
		virtual void		makeSound() const = 0;
		const std::string	&getType() const;
		void				setType(const std::string &type);

	protected:
		std::string	_type;
};

#endif