/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 16:02:29 by mbirou            #+#    #+#             */
/*   Updated: 2025/03/19 11:29:47 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T>
void	swap(T &a, T &b)
{
	T	c = b;
	b = a;
	a = c;
}

template <typename T>
T	min(const T &a, const T &b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T>
T	max(const T &a, const T &b)
{
	if (a > b)
		return (a);
	return (b);
}
