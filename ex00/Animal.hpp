/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 13:40:32 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/09 17:00:35 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <spellBook.hpp>
#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(const Animal &src);
		Animal	&operator =(const Animal &rhs);
		~Animal();
	
		virtual void		makeSound() const;
		const std::string	&getType() const;
		void				setType(const std::string &type);

	protected:
		std::string	_type;
};

#endif