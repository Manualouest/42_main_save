/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_token_trimmer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:29:10 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/01 16:55:55 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

static void	ms_trimmer(t_params *param, t_params *tp_param, int *len,
				int *last_len)
{
	char	*tp_char;

	if (param->text[*len] == ' ')
	{
		if (*len > 0)
		{
			tp_param = param->next;
			param->next = NULL;
			param->next = malloc(sizeof(*param));
			param->next->type = STRING;
			param->next->symbol = NO_SYMBOL;
			param->next->quote_level = param->quote_level;
			param->next->text = ft_substr(param->text, *len + 1, *last_len);
			param->next->next = tp_param;
			*last_len = *len;
		}
		while (--*len >= 0 && param->text[*len] == ' ')
			;
	}
	else if (*len == 0 && *last_len != (int)ft_strlen(param->text))
	{
		tp_char = ft_substr(param->text, 0, *last_len);
		free(param->text);
		param->text = tp_char;
	}
}

void	ms_cut_spaces(t_command *cmd, t_params *param)
{
	int			len;
	int			last_len;
	t_params	*tp_param;

	tp_param = NULL;
	while (param)
	{
		if (param->type == STRING && param->quote_level == 0)
		{
			len = ft_strlen(param->text);
			last_len = len;
			while (--len >= 0 && param->text[len])
				ms_trimmer(param, tp_param, &len, &last_len);
		}
		param = param->next;
	}
	param = cmd->params;
}
