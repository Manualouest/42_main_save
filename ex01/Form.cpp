/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:08:17 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/04 12:55:19 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Goofy Goober attestation"), _isSigned(false), _signGrade(2), _execGrade(2)
{
	if (getSignGrade() < 1 || getExecGrade() < 1)
		throw (Form::GradeTooHighException());
	if (getSignGrade() > 150 || getExecGrade() > 150)
		throw (Form::GradeTooLowException());
	PRINT GRN BOLD "Form: " UNDL AND getName() AND GRN BOLD " has been photocopied 🖨️" CLR ENDL;
}

Form::Form(const std::string &name, const int &signGrade, const int &execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (getSignGrade() < 1 || getExecGrade() < 1)
		throw (Form::GradeTooHighException());
	if (getSignGrade() > 150 || getExecGrade() > 150)
		throw (Form::GradeTooLowException());
	PRINT GRN BOLD "Form: " UNDL AND getName() AND GRN BOLD " has been photocopied 🖨️" CLR ENDL;
}

Form::Form(const Form &src) : _name(src.getName()), _isSigned(src.getStatus()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	if (getSignGrade() < 1 || getExecGrade() < 1)
		throw (Form::GradeTooHighException());
	if (getSignGrade() > 150 || getExecGrade() > 150)
		throw (Form::GradeTooLowException());
	PRINT GRN BOLD "Form: " UNDL AND src.getName() AND GRN BOLD " has been scanned 😲" CLR ENDL;
}

Form	&Form::operator =(const Form &rhs)
{
	PRINT GRN BOLD "Form: " UNDL AND getName() AND GRN BOLD " is been repurposed 😲" CLR ENDL;
	if (this != &rhs)
		_isSigned = rhs.getStatus();
	return (*this);
}

std::ostream 	&operator <<(std::ostream &ost, const Form &rhs)
{
	ost AND CYN BOLD "Form " UNDL AND rhs.getName() AND CYN BOLD ", ";
	if (rhs.getStatus())
		PRINT "Signed. ";
	else
		PRINT "Not yet signed. ";
	PRINT "Req grade; -to sign: " AND rhs.getSignGrade() AND ", -to execute: " AND rhs.getExecGrade() AND CLR ENDL;
	return (ost);
}

Form::~Form()
{
	PRINT DSTR BOLD "Form " AND getName() AND " has been shredded ✂️" CLR ENDL;
}

const std::string	&Form::getName() const
{
	return (_name);
}

const bool			&Form::getStatus() const
{
	return (_isSigned);
}

const int			&Form::getSignGrade() const
{
	return (_signGrade);
}

const int			&Form::getExecGrade() const
{
	return (_execGrade);
}

void	Form::beSigned(const Bureaucrat &employee)
{
	if (employee.getGrade() > getSignGrade())
		throw (Form::GradeTooLowException());
	if (_isSigned)
		throw (Form::FormAlreadySignedExeption());
	_isSigned = true;
}

const char *Form::GradeTooLowException::what() const throw ()
{
	return (RED BOLD "Even Cats would've been able to sign your form 🤦" CLR);
}

const char *Form::GradeTooHighException::what() const throw ()
{
	return (RED BOLD "AH yes! make a form that nobody can sign 😐" CLR);
}

const char *Form::FormAlreadySignedExeption::what() const throw ()
{
	return (RED BOLD "This is already signed 😐" CLR);
}
