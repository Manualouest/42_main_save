/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 08:00:57 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/30 15:05:53 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <spellBook.hpp>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat(const std::string &name, const int &grade);
		Bureaucrat	&operator =(const Bureaucrat &rhs);
		~Bureaucrat();

		const std::string	&getName() const;
		const int			&getGrade() const;
		void				upGrade();
		void				downGrade();

	private:
		std::string	_name;
		int			_grade;

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
};

std::ostream 	&operator <<(std::ostream &ost, const Bureaucrat &rhs);
