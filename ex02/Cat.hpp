/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:02:49 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/11 16:02:14 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <spellBook.hpp>
# include <iostream>

class Cat : public AAnimal
{
	public:
		Cat();
		Cat(const Cat &src);
		Cat	&operator =(const Cat &rhs);
		~Cat();

		void	makeSound() const;
		Brain	*getBrainAddr() const;

	private:
		Brain	*_brain;
};

#endif