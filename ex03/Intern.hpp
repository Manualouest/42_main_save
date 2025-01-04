/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:30:30 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/04 14:53:34 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include <iostream>
# include <spellBook.hpp>

class Intern
{
	public:
		Intern();
		Intern(const Intern &src);
		const Intern	&operator =(const Intern &rhs);
		~Intern();

		AForm	*makeForm(const std::string &name, const std::string &target);

		class UnknownFormNameExeption : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};