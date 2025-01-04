/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 10:08:27 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/04 12:47:29 by mbirou           ###   ########.fr       */
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
		virtual ~AForm();

		const std::string			&getName() const;
		const bool					&getStatus() const;
		const int					&getSignGrade() const;
		const int					&getExecGrade() const;
		virtual const std::string	&getTarget() const = 0;
		void						beSigned(const Bureaucrat &employee);
		void						execute(Bureaucrat const & executor) const;
		virtual void				formAction() const = 0;

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

		class FormNotSignedExeption : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream 	&operator <<(std::ostream &ost, const AForm &rhs);

