/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 08:00:53 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/29 17:54:37 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
	_name = "Marvin";
	_grade = 1;
	PRINT GRN BOLD "Welcome to our new employee Marvin 👏" CLR ENDL;
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	_name = name;
	_grade = grade;
	PRINT GRN BOLD "Welcome to our new employee " AND getName() AND" 👏" CLR ENDL;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
{
	*this = src;
	PRINT GRN BOLD "Welcome to " AND src.getName() AND"'s twin 👏" CLR ENDL;
}

Bureaucrat	&Bureaucrat::operator =(const Bureaucrat &rhs)
{
	PRINT GRN BOLD "Did someone just clone " AND rhs.getName() AND"? 🤨" CLR ENDL;
	if (this != &rhs)
	{
		_name = rhs.getName();
		_grade = rhs.getGrade();
	}
	return (*this);
}

std::ostream	&operator <<(std::ostream &ost, const Bureaucrat &rhs)
{
	ost AND CYN UNDL BOLD "Mr/rs " AND rhs.getName() AND "; grade " AND rhs.getGrade() AND CLR;
	return (ost);
}

Bureaucrat::~Bureaucrat()
{
	PRINT DSTR BOLD "Oh no " AND getName() AND " got fired 😰" CLR ENDL;
}

const std::string &Bureaucrat::getName() const
{
	return (_name);
}

const int	&Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::upGrade()
{
	if (_grade == 1)
		throw (Bureaucrat::GradeTooHighException());
	_grade -= 1;
}

void	Bureaucrat::downGrade()
{
	if (_grade == 150)
		throw (Bureaucrat::GradeTooLowException());
	_grade += 1;
}

void	Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		PRINT CYN BOLD "Mr/rs " AND getName() AND " was able to sign " AND form.getName() AND CLR ENDL;
	}
	catch (AForm::GradeTooLowException)
	{
		PRINT RED BOLD "Oopsie " AND getName() AND ", seems like your grade is " AND getGrade() - form.getSignGrade() AND " too low to sign " AND form.getName() AND CLR ENDL;
	}
	catch (AForm::FormAlreadySignedExeption)
	{
		PRINT RED BOLD AND getName() AND " this " AND form.getName() AND " is already signed 😐" CLR ENDL;
	}
}

const char *Bureaucrat::GradeTooLowException::what() const throw ()
{
	return (RED BOLD "Budy isn't 150 low enought? 🤨" CLR);
}

const char *Bureaucrat::GradeTooHighException::what() const throw ()
{
	return (RED BOLD "Nuh uh that's way too high! 🙅" CLR);
}
