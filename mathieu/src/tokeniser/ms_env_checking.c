/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_checking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:03:30 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/28 20:33:32 by mbirou           ###   ########.fr       */
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
		if (quote_level % 2 == 0 && arg[index] == '$' && arg[index + 1]
			&& arg[index + 1] != ' ' && ((arg[index + 1] != -1
			&& arg[index + 1] != -2 && quote_level != 0) || quote_level == 0))
			return (1);
	}
	return (0);
}
