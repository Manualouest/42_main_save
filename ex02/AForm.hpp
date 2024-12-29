/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:08:27 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/29 17:57:16 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Bureaucrat;
# include "Bureaucrat.hpp"
# include <iostream>
# include <spellBook.hpp>

class AForm
{
	public:
		AForm();
		AForm(const std::string &name, const int &signGrade, const int &execGrade);
		AForm(const AForm &src);
		AForm	&operator =(const AForm &rhs);
		~AForm();

		virtual const std::string	&getName() const;
		virtual const bool			&getStatus() const;
		virtual const int			&getSignGrade() const;
		virtual const int			&getExecGrade() const;
		virtual void				beSigned(const Bureaucrat &employee) = 0;

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;

	public:
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FormAlreadySignedExeption : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream 	&operator <<(std::ostream &ost, const AForm &rhs);

