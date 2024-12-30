/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:08:17 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/30 16:36:07 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Goofy Goober attestation"), _isSigned(false), _signGrade(2), _execGrade(2)
{
	if (getSignGrade() < 1 || getExecGrade() < 1)
		throw (AForm::GradeTooHighException());
	if (getSignGrade() > 150 || getExecGrade() > 150)
		throw (AForm::GradeTooLowException());
	PRINT GRN BOLD "AForm: " UNDL AND getName() AND GRN BOLD " has been photocopied 🖨️" CLR ENDL;
}

AForm::AForm(const std::string &name, const int &signGrade, const int &execGrade) : _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (getSignGrade() < 1 || getExecGrade() < 1)
		throw (AForm::GradeTooHighException());
	if (getSignGrade() > 150 || getExecGrade() > 150)
		throw (AForm::GradeTooLowException());
	PRINT GRN BOLD "AForm: " UNDL AND getName() AND GRN BOLD " has been photocopied 🖨️" CLR ENDL;
}

AForm::AForm(const AForm &src) : _name(src.getName()), _isSigned(src.getStatus()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade())
{
	if (getSignGrade() < 1 || getExecGrade() < 1)
		throw (AForm::GradeTooHighException());
	if (getSignGrade() > 150 || getExecGrade() > 150)
		throw (AForm::GradeTooLowException());
	PRINT GRN BOLD "AForm: " UNDL AND src.getName() AND GRN BOLD " has been scanned 😲" CLR ENDL;
}

AForm	&AForm::operator =(const AForm &rhs)
{
	PRINT GRN BOLD "AForm: " UNDL AND getName() AND GRN BOLD " is been repurposed 😲" CLR ENDL;
	if (this != &rhs)
		_isSigned = rhs.getStatus();
	return (*this);
}

std::ostream 	&operator <<(std::ostream &ost, const AForm &rhs)
{
	ost AND CYN UNDL BOLD "AForm " AND rhs.getName() AND ", ";
	if (rhs.getStatus())
		PRINT "Signed. ";
	else
		PRINT "Not yet signed. ";
	PRINT "Req grade; -to sign: " AND rhs.getSignGrade() AND ", -to execute: " AND rhs.getExecGrade() AND CLR ENDL;
	return (ost);
}

AForm::~AForm()
{
	PRINT DSTR BOLD "AForm " AND getName() AND " has been shredded ✂️" CLR ENDL;
}

const std::string	&AForm::getName() const
{
	return (_name);
}

const bool			&AForm::getStatus() const
{
	return (_isSigned);
}

const int			&AForm::getSignGrade() const
{
	return (_signGrade);
}

const int			&AForm::getExecGrade() const
{
	return (_execGrade);
}


void	AForm::beSigned(const Bureaucrat &employee)
{
	if (employee.getGrade() > getSignGrade())
		throw (AForm::GradeTooLowException());
	if (_isSigned)
		throw (AForm::FormAlreadySignedExeption());
	_isSigned = true;
}

const char *AForm::GradeTooLowException::what() const throw ()
{
	return (RED BOLD "Even Cats would've been able to sign your Aform 🤦" CLR);
}

const char *AForm::GradeTooHighException::what() const throw ()
{
	return (RED BOLD "AH yes! make a Aform that nobody can sign 😐" CLR);
}

const char *AForm::FormAlreadySignedExeption::what() const throw ()
{
	return (RED BOLD "This is already signed 😐" CLR);
}
