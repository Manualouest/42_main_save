/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 08:49:21 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/29 16:49:32 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	Marvin;
	Bureaucrat	Jhon("Jhon", 145);
	Bureaucrat	Steve("Steve", 150);

	NEWL;
	PRINT RGB(255, 165, 0) BOLD "╔═════════════════════════════════════════════" CLR ENDL;
	PRINT RGB(255, 165, 0) BOLD "║ Cannon check" CLR ENDL ENDL;

	Form goof;
	Form contract("important contract", 15, 15);
	Form order("random document", 145, 145);
	Form order2(order);
	Form order3("useless document", 150, 150);
	order3 = order2;

	NEWL;
	PRINT RGB(255, 165, 0) BOLD "╔═════════════════════════════════════════════" CLR ENDL;
	PRINT RGB(255, 165, 0) BOLD "║ Bad construction check" CLR ENDL ENDL;

	try
	{
		PRINT BOLD "Sign grade of 0" ENDL;
		Form	high("too high", 0, 0);
	}
	catch (Form::GradeTooHighException &e)
	{
		PRINT e.what() ENDL;
	}

	try
	{
		PRINT BOLD "Sign grade of 151" ENDL;
		Form	low("too low", 151, 151);
	}
	catch (Form::GradeTooLowException &e)
	{
		PRINT e.what() ENDL;
	}

	NEWL;
	PRINT RGB(255, 165, 0) BOLD "╔═════════════════════════════════════════════" CLR ENDL;
	PRINT RGB(255, 165, 0) BOLD "║ signing check" CLR ENDL ENDL;

	Marvin.signForm(order3);
	NEWL;
	Marvin.signForm(goof);
	NEWL;
	Jhon.signForm(order2);
	NEWL;
	Jhon.signForm(contract);
	NEWL;
	Steve.signForm(contract);
	NEWL;
	Steve.signForm(order3);

	NEWL;
	PRINT RGB(255, 165, 0) BOLD "╔═════════════════════════════════════════════" CLR ENDL;
	PRINT RGB(255, 165, 0) BOLD "║ The End" CLR ENDL ENDL;
}
