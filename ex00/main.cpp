/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 08:49:21 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/29 16:36:34 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	PRINT RGB(255, 165, 0) BOLD "╔═════════════════════════════════════════════" CLR ENDL;
	PRINT RGB(255, 165, 0) BOLD "║ Cannon check" CLR ENDL ENDL;
	Bureaucrat	Marvin;
	Bureaucrat	Jhon("Jhon", 150);
	Bureaucrat	Jhonjr(Jhon);

	NEWL;
	PRINT RGB(255, 165, 0) BOLD "╔═════════════════════════════════════════════" CLR ENDL;
	PRINT RGB(255, 165, 0) BOLD "║ Bad construction check" CLR ENDL ENDL;

	try
	{
		PRINT BOLD "Grade of 0" ENDL;
		Bureaucrat	high("Steve", 0);
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		PRINT e.what() ENDL;
	}

	try
	{
		PRINT BOLD "Grade of 151" ENDL;
		Bureaucrat	low("Steve", 151);
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		PRINT e.what() ENDL;
	}


	NEWL;
	PRINT RGB(255, 165, 0) BOLD "╔═════════════════════════════════════════════" CLR ENDL;
	PRINT RGB(255, 165, 0) BOLD "║ Grade modification check" CLR ENDL ENDL;

	PRINT BOLD "Marvin's high tier grade: " AND Marvin ENDL;
	Marvin.downGrade();
	PRINT BOLD "Decreased Marvin's grade: " AND Marvin ENDL;
	Marvin.upGrade();
	PRINT BOLD "Increased Marvin's grade: " AND Marvin ENDL;

	NEWL;
	PRINT RGB(255, 165, 0) BOLD "╔═════════════════════════════════════════════" CLR ENDL;
	PRINT RGB(255, 165, 0) BOLD "║ Bad grade modification check" CLR ENDL ENDL;

	try
	{
		PRINT Marvin ENDL AND BOLD "Now trying to increase grade" ENDL;
		Marvin.upGrade();
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		PRINT e.what() ENDL;
	}
	PRINT Marvin ENDL;
	NEWL;
	try
	{
		PRINT Jhon ENDL AND BOLD "Now trying to decrease grade" ENDL;
		Jhon.downGrade();
	}
	catch (Bureaucrat::GradeTooLowException &e)
	{
		PRINT e.what() ENDL;
	}
	PRINT Jhon ENDL;

	NEWL;
	PRINT RGB(255, 165, 0) BOLD "╔═════════════════════════════════════════════" CLR ENDL;
	PRINT RGB(255, 165, 0) BOLD "║ The End" CLR ENDL ENDL;
}
