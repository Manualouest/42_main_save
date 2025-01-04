/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:21:53 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/04 12:48:28 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.hpp"
# include <iostream>
# include <fstream>
# include <spellBook.hpp>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm	&operator =(const ShrubberyCreationForm &rhs);
		~ShrubberyCreationForm();

		const std::string	&getTarget() const;

	private:
		std::string	_target;
		void	formAction() const;

	public:
		class FileCreationFailedExeption : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};