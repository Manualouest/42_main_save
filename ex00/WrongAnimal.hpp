/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:21:11 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/10 14:22:27 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <spellBook.hpp>
#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &src);
		WrongAnimal	&operator =(const WrongAnimal &rhs);
		~WrongAnimal();

		void				makeSound() const;
		const std::string	&getType() const;
		void				setType(const std::string &type);

	protected:
		std::string	_type;
};

#endif