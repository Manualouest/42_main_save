/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:21:43 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/04 12:48:24 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AForm.hpp"
# include <iostream>
# include <ctime>
# include <cstdlib>
# include <spellBook.hpp>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm	&operator =(const RobotomyRequestForm &rhs);
		~RobotomyRequestForm();

		const std::string	&getTarget() const;

	private:
		std::string	_target;
		void	formAction() const;
};