/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:08:27 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/29 16:37:06 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Bureaucrat;
# include "Bureaucrat.hpp"
# include <iostream>
# include <spellBook.hpp>

class Form
{
	public:
		Form();
		Form(const std::string &name, const int &signGrade, const int &execGrade);
		Form(const Form &src);
		Form	&operator =(const Form &rhs);
		~Form();

		const std::string	&getName() const;
		const bool			&getStatus() const;
		const int			&getSignGrade() const;
		const int			&getExecGrade() const;
		void				beSigned(const Bureaucrat &employee);

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

std::ostream 	&operator <<(std::ostream &ost, const Form &rhs);

