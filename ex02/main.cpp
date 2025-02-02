/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 08:49:21 by mbirou            #+#    #+#             */
/*   Updated: 2025/02/02 21:18:53 by mbirou           ###   ########.fr       */
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
	Bureaucrat	Jhon("Jhon", 70);
	Bureaucrat	Steve("Steve", 145);

	AForm	*rob = new RobotomyRequestForm("Jhon");
	AForm	*shrub = new ShrubberyCreationForm("Steve");
	AForm	*pres = new PresidentialPardonForm("Marvin");
	AForm	*dupPres = new PresidentialPardonForm("Bob");

	PRINT BOLD AND *pres AND *rob AND *shrub;

	NEWL;
	PRINT RGB(255, 165, 0) BOLD "╔═════════════════════════════════════════════" CLR ENDL;
	PRINT RGB(255, 165, 0) BOLD "║ Sign check" CLR ENDL ENDL;

	PRINT BOLD "Jhon tries to sign pres." CLR ENDL;
	Jhon.signForm(*pres);

	PRINT BOLD "Jhon tries to sign rob." CLR ENDL;
	Jhon.signForm(*rob);

	PRINT BOLD "Steve tries to sign shrub." CLR ENDL;
	Steve.signForm(*shrub);

	PRINT BOLD "Marvin tries to sign pres." CLR ENDL;
	Marvin.signForm(*pres);

	PRINT BOLD "Marvin tries to sign pres." CLR ENDL;
	Marvin.signForm(*pres);

	NEWL;
	PRINT RGB(255, 165, 0) BOLD "╔═════════════════════════════════════════════" CLR ENDL;
	PRINT RGB(255, 165, 0) BOLD "║ Execute check" CLR ENDL ENDL;

	PRINT BOLD "Jhon tries to execute rob." CLR ENDL;
	Jhon.executeForm(*rob);

	PRINT BOLD "Steve tries to execute shrub." CLR ENDL;
	Steve.executeForm(*shrub);
	
	PRINT BOLD "Jhon tries to execute shrub." CLR ENDL;
	Jhon.executeForm(*shrub);

	PRINT BOLD "Marvin tries to execute rob." CLR ENDL;
	Marvin.executeForm(*rob);
	
	PRINT BOLD "Marvin tries to execute pres." CLR ENDL;
	Marvin.executeForm(*pres);
	
	PRINT BOLD "Marvin tries to execute dupPres." CLR ENDL;
	Marvin.executeForm(*dupPres);

	NEWL;
	PRINT RGB(255, 165, 0) BOLD "╔═════════════════════════════════════════════" CLR ENDL;
	PRINT RGB(255, 165, 0) BOLD "║ The End" CLR ENDL ENDL;

	delete dupPres;
	delete pres;
	delete rob;
	delete shrub;
}
