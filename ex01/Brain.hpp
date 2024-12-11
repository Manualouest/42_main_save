/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:56:22 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/11 14:55:52 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <spellBook.hpp>
# include <iostream>

class Brain
{
	public:
		Brain();
		Brain(const Brain &src);
		Brain &operator =(const Brain &rhs);
		~Brain();

	private:
		std::string	_ideas[100];
};

#endif