/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 08:49:21 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/30 17:45:53 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int	main(void)
{
	Bureaucrat	Marvin;
	Bureaucrat	Jhon("Jhon", 145);
	Bureaucrat	Steve("Steve", 150);

	NEWL;
	PRINT RGB(255, 165, 0) BOLD "╔═════════════════════════════════════════════" CLR ENDL;
	PRINT RGB(255, 165, 0) BOLD "║ TESTS" CLR ENDL ENDL;

	AForm	*pres = new PresidentialPardonForm("steve");
	AForm	*pres2(pres);

	Marvin.signForm(*pres);
	pres->execute(Marvin);

	NEWL;
	PRINT RGB(255, 165, 0) BOLD "╔═════════════════════════════════════════════" CLR ENDL;
	PRINT RGB(255, 165, 0) BOLD "║ The End" CLR ENDL ENDL;

	delete pres;
	(void)pres2;
}
