/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exit_pre_execheck.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 06:30:13 by mbirou            #+#    #+#             */
/*   Updated: 2024/05/19 19:50:08 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>

static int	ms_is_there_multiple_parameters(t_params *params)
{
	t_params	*cpy_params;
	int			i;

	cpy_params = params;
	while (cpy_params != NULL)
	{
		if (cpy_params->type == STRING && cpy_params->quote_level == 0)
		{
			i = -1;
			while (cpy_params->text[++i])
				if (cpy_params->text[i] == ' ')
					return (1);
		}
		cpy_params = cpy_params->next;
	}
	return (0);
}

void	ms_check_for_bad_param(t_command *command)
{
	t_params	*param;
	t_params	*prev_param;
	int			i;

	param = command->params;
	prev_param = NULL;
	while (param != NULL)
	{
		if (param->type == STRING
			&& !((prev_param && prev_param->symbol >= INPUT
					&& prev_param->symbol <= APPEND)
				|| (param->next && param->next->symbol >= INPUT
					&& param->next->symbol <= APPEND)))
		{
			i = -1;
			while (param->text && param->text[++i])
				if (!ft_isdigit(param->text[i]))
					command->error = BAD_PARAM;
		}
		prev_param = param;
		param = param->next;
	}
}

void	ms_exit_pre_parsing(t_command *command)
{
	int	i;

	if (ms_is_there_multiple_parameters(command->params))
		command->error = TOO_MANY_ARGUMENT;
	i = -1;
	if (command->params && command->params->type != STRING
		&& command->error == NO_ERROR)
		command->error = BAD_PARAM;
	while (command->params && command->params->text
		&& command->params->text[++i]
		&& command->error == NO_ERROR)
	{
		if (command->params->text[i] == ' '
			&& command->params->text[i + 1] != 0)
			command->error = TOO_MANY_ARGUMENT;
	}
	ms_check_for_bad_param(command);
}
