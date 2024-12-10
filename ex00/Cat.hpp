/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:02:49 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/09 17:01:53 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <spellBook.hpp>
# include <iostream>

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &src);
		Cat	&operator =(const Cat &rhs);
		~Cat();

		void	makeSound() const;
};

#endif