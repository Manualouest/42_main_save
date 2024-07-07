/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_checking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:03:30 by mbirou            #+#    #+#             */
/*   Updated: 2024/07/07 17:47:29 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

int	ms_has_dollar(char *arg)
{
	int	index;
	int	quote_level;

	quote_level = 0;
	index = -1;
	if (!arg)
		return (0);
	while (arg[++index])
	{
		quote_level = ms_change_quote_level(arg, index, quote_level);
		if (quote_level % 2 == 0 && arg[index] == '$'
			&& (index == 0 || (index > 0 && arg[index - 1] != '\\')))
			return (1);
	}
	return (0);
}
