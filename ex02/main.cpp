/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 08:49:21 by mbirou            #+#    #+#             */
/*   Updated: 2025/02/02 10:15:15 by mbirou           ###   ########.fr       */
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

	try
	{
		PRINT BOLD "Jhon tries to sign pres." CLR ENDL;
		Jhon.signForm(*pres);
	}
	catch (AForm::GradeTooLowException &e)
	{
		PRINT e.what() ENDL;
	}
	try
	{
		PRINT BOLD "Jhon tries to sign rob." CLR ENDL;
		Jhon.signForm(*rob);
	}
	catch (AForm::GradeTooLowException &e)
	{
		PRINT e.what() ENDL;
	}
	try
	{
		PRINT BOLD "Steve tries to sign shrub." CLR ENDL;
		Steve.signForm(*shrub);
	}
	catch (AForm::GradeTooLowException &e)
	{
		PRINT e.what() ENDL;
	}
	try
	{
		PRINT BOLD "Marvin tries to sign pres." CLR ENDL;
		Marvin.signForm(*pres);
	}
	catch (AForm::GradeTooLowException &e)
	{
		PRINT e.what() ENDL;
	}
	try
	{
		PRINT BOLD "Marvin tries to sign pres." CLR ENDL;
		Marvin.signForm(*pres);
	}
	catch (AForm::FormAlreadySignedExeption &e)
	{
		PRINT e.what() ENDL;
	}

	NEWL;
	PRINT RGB(255, 165, 0) BOLD "╔═════════════════════════════════════════════" CLR ENDL;
	PRINT RGB(255, 165, 0) BOLD "║ Execute check" CLR ENDL ENDL;

	try
	{
		PRINT BOLD "Jhon tries to execute rob." CLR ENDL;
		rob->execute(Jhon);
	}
	catch (AForm::GradeTooLowException &e)
	{
		PRINT RED BOLD "Grade too low to execute" CLR ENDL;
	}
	try
	{
		PRINT BOLD "Steve tries to execute shrub." CLR ENDL;
		shrub->execute(Steve);
	}
	catch (ShrubberyCreationForm::FileCreationFailedExeption &e)
	{
		PRINT e.what() ENDL;
	}
	catch (AForm::GradeTooLowException &e)
	{
		PRINT RED BOLD "Grade too low to execute" CLR ENDL;
	}
	try
	{
		PRINT BOLD "Jhon tries to execute shrub." CLR ENDL;
		shrub->execute(Jhon);
	}
	catch (ShrubberyCreationForm::FileCreationFailedExeption &e)
	{
		PRINT e.what() ENDL;
	}
	catch (AForm::GradeTooLowException &e)
	{
		PRINT RED BOLD "Grade too low to execute" CLR ENDL;
	}
	try
	{
		PRINT BOLD "Marvin tries to execute rob." CLR ENDL;
		rob->execute(Marvin);
	}
	catch (AForm::GradeTooLowException &e)
	{
		PRINT RED BOLD "Grade too low to execute" CLR ENDL;
	}
	try
	{
		PRINT BOLD "Marvin tries to execute pres." CLR ENDL;
		pres->execute(Marvin);
	}
	catch (AForm::GradeTooLowException &e)
	{
		PRINT RED BOLD "Grade too low to execute" CLR ENDL;
	}
	try
	{
		PRINT BOLD "Marvin tries to execute dupPres." CLR ENDL;
		dupPres->execute(Marvin);
	}
	catch (AForm::FormNotSignedExeption &e)
	{
		PRINT e.what() ENDL;
	}

	NEWL;
	PRINT RGB(255, 165, 0) BOLD "╔═════════════════════════════════════════════" CLR ENDL;
	PRINT RGB(255, 165, 0) BOLD "║ The End" CLR ENDL ENDL;

	delete dupPres;
	delete pres;
	delete rob;
	delete shrub;
}
