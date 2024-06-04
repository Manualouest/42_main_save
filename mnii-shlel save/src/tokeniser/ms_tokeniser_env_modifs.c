/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokeniser_env_modifs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 02:24:56 by mbirou            #+#    #+#             */
/*   Updated: 2024/05/17 18:02:12 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

int	ms_get_len_of_env(char *param)
{
	int	len;

	len = 0;
	while (param[len] && ((ms_is_symbol(param[len]) == ms_is_symbol(param[0])
				&& param[len] != ' ') || len == 0))
		len ++;
	return (len);
}

int	ms_is_it_worth_modifying_params(char *param)
{
	if (!param || ft_strlen(param) == (size_t)ms_get_len_of_env(param))
		return (0);
	return (1);
}

void	ms_redo_next_param(t_params *param)
{
	int		start;
	int		len;
	char	*tp_char;

	start = ms_get_len_of_env(param->text);
	len = ft_strlen(param->text) - start;
	tp_char = ft_substr(param->text, start, len);
	free(param->text);
	param->text = tp_char;
}

void	ms_remove_last_useless_space(t_params *param)
{
	char	*tp_char;
	int		i;

	i = ft_strlen(param->text) - 1;
	while (param->text && param->text[i] && param->text[i] == ' ')
		i --;
	if (i != (int)ft_strlen(param->text) - 1)
	{
		tp_char = ft_substr(param->text, 0, i + 1);
		free(param->text);
		param->text = tp_char;
	}
}

void	ms_make_env_easier(t_params *main_params)
{
	t_params	*copy_params;
	t_params	*tp_params;

	copy_params = main_params;
	while (copy_params != NULL)
	{
		if (copy_params->symbol == DOLLAR && copy_params->next->type == STRING
			&& copy_params->quote_level % 2 == 0
			&& ms_is_it_worth_modifying_params(copy_params->next->text))
		{
			tp_params = copy_params->next;
			copy_params->next = NULL;
			copy_params->next = malloc(sizeof(*copy_params->next));
			copy_params->next->symbol = NO_SYMBOL;
			copy_params->next->quote_level = tp_params->quote_level;
			copy_params->next->type = STRING;
			copy_params->next->text = ft_substr(tp_params->text, 0,
					ms_get_len_of_env(tp_params->text));
			ms_redo_next_param(tp_params);
			copy_params->next->next = tp_params;
		}
		if (copy_params->next == NULL && copy_params->type == STRING)
			ms_remove_last_useless_space(copy_params);
		copy_params = copy_params->next;
	}
}
