/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:26:11 by mbirou            #+#    #+#             */
/*   Updated: 2025/02/07 15:03:28 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <iostream>
#include <spellBook.hpp>

class RPN
{
	public:
		static void	rpn(const std::string &expression);

	private:
		RPN();
		RPN(const RPN &src);
		RPN	&operator =(const RPN &rhs);
		~RPN();
};
