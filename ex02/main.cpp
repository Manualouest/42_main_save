/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 08:49:21 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/01 18:21:15 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat	Marvin;
	Bureaucrat	Jhon("Jhon", 145);
	Bureaucrat	Steve("Steve", 150);

	NEWL;
	PRINT RGB(255, 165, 0) BOLD "╔═════════════════════════════════════════════" CLR ENDL;
	PRINT RGB(255, 165, 0) BOLD "║ TESTS" CLR ENDL ENDL;

	AForm	*pres = new PresidentialPardonForm("steve");
	AForm	*rob = new RobotomyRequestForm("steve");
	AForm	*shrub = new ShrubberyCreationForm("steve");

	Marvin.signForm(*pres);
	pres->execute(Marvin);

	Marvin.signForm(*rob);
	rob->execute(Marvin);

	Marvin.signForm(*shrub);
	shrub->execute(Marvin);

	NEWL;
	PRINT RGB(255, 165, 0) BOLD "╔═════════════════════════════════════════════" CLR ENDL;
	PRINT RGB(255, 165, 0) BOLD "║ The End" CLR ENDL ENDL;

	delete pres;
	delete rob;
	delete shrub;
}
