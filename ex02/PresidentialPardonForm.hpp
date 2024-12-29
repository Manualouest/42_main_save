/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 19:03:46 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/29 19:10:23 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.hpp"
# include <iostream>
# include <spellBook.hpp>

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm	&operator =(const PresidentialPardonForm &rhs);
		~PresidentialPardonForm();

		virtual const std::string	&getName() const;
		virtual const bool			&getStatus() const;
		virtual const int			&getSignGrade() const;
		virtual const int			&getExecGrade() const;
		virtual void				beSigned(const Bureaucrat &employee) = 0;
		void						bePardoned() const;

	private:
		std::string	_target
};