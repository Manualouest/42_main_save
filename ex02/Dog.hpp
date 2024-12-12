/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 13:59:35 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/12 11:55:10 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <spellBook.hpp>
# include <iostream>

class Dog : public AAnimal
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