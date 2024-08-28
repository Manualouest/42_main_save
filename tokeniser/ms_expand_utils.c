/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_expand_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 19:27:16 by mbirou            #+#    #+#             */
/*   Updated: 2024/08/25 19:28:36 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

void	ms_setup_var_info(char ***args, int index, int *var_pos, int *var_len)
{
	*var_len = 0;
	*var_pos = ms_get_var_start(args[0][index], var_len);
	*var_len -= 1;
}

char	*ms_replace_str(char *original, char *new)
{
	free(original);
	return (new);
}

char	ms_get_quote_to_index(char *arg, int pos)
{
	int	i;
	int	quote_level;

	i = -1;
	quote_level = 0;
	while (arg[++i] && i <= pos)
		quote_level = ms_change_quote_level(arg, i, quote_level);
	if (quote_level == 1)
		return ((char)(-2));
	else if (quote_level == 2)
		return ((char)(-1));
	return (0);
}
