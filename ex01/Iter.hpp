/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 17:02:09 by mbirou            #+#    #+#             */
/*   Updated: 2025/03/19 11:35:00 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename T, typename F>
void	iter(T *array, int arrayLen, void (*f)(F))
{
	for (int i = 0; i < arrayLen; ++i)
		f(array[i]);
}
