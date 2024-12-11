/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:59:35 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/11 15:34:34 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <spellBook.hpp>
# include <iostream>

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &src);
		Dog	&operator =(const Dog &rhs);
		~Dog();

		void	makeSound() const;
		Brain	*getBrainAddr() const;

	private:
		Brain	*_brain;
};

#endif