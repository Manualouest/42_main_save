/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:46:32 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/01 18:04:34 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
	_target = "The Shadow Wizard Money Gang";;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm("RobotomyRequestForm", 72, 45)
{
	*this = src;
}

RobotomyRequestForm	&RobotomyRequestForm::operator =(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
		_target = rhs._target;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void	RobotomyRequestForm::formAction() const
{
	PRINT CYN BOLD "*Bvvvvvvvvvv*" CLR ENDL;
	PRINT CYN BOLD "Bip Bop Bi Boop" CLR ENDL;
	PRINT CYN BOLD "*Clank* *Clank* *Clank*" CLR ENDL;
	std::srand(std::time(NULL));
	if (std::rand() % 2)
	{
		PRINT CYN BOLD "Process successfull 🤖" CLR ENDL;
		PRINT CYN BOLD AND _target AND " has been robotomized" CLR ENDL;
	}
	else
	{
		PRINT CYN BOLD "Process unsuccessfull 🤖" CLR ENDL;
		PRINT CYN BOLD AND _target AND " hasn't been robotomized" CLR ENDL;
	}
}