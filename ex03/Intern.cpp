/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:30:28 by mbirou            #+#    #+#             */
/*   Updated: 2025/02/02 21:29:41 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	PRINT GRN BOLD "yay we have a new Intern 🥳" CLR ENDL;
}

Intern::Intern(const Intern &src)
{
	*this = src;
}

const Intern	&Intern::operator =(const Intern &rhs)
{
	return (rhs);
}

Intern::~Intern()
{
	PRINT DSTR BOLD "Nooooooooooooooooooo the intern left" CLR ENDL;
}

int	searchName(const std::string &name)
{
	std::string formNames[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	for (int i = 0; i < 3; ++i)
		if (formNames[i] == name)
			return (i);
	return (-1);
}

AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	AForm	*form;

	switch (searchName(name))
	{
		case (0):
			form = new PresidentialPardonForm(target);
			break;
		case (1):
			form = new RobotomyRequestForm(target);
			break;
		case (2):
			form = new ShrubberyCreationForm(target);
			break;
		default:
			throw (Intern::UnknownFormNameExeption());
	}
	PRINT CYN BOLD UNDL "<<Some intern created a " AND form->getName() AND ">>" CLR ENDL;
	return (form);
}

const char *Intern::UnknownFormNameExeption::what() const throw()
{
	return (RED BOLD "You're devious for asking that poor intern something that doesn't exist!" CLR);
}
