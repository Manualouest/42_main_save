/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_structure_translator_main.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 18:11:10 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/10 18:20:33 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

static char	*ms_get_command(t_command *command)
{
	char	*args;

	args = malloc(sizeof(char) * ft_strlen(command->cmd) + 1);
	args[0] = 0;
	ft_strlcpy(args, command->cmd, ft_strlen(command->cmd) + 1);
	return (args);
}

static int	ms_get_nb_param(t_params *main_params)
{
	t_params	*params;
	int			i;

	params = main_params;
	i = 0;
	while (params != NULL)
	{
		i ++;
		params = params->next;
	}
	return (i);
}

static void	ms_copy_without_end_space(char **list, char *text, int size)
{
	int	i;

	if (size > 0 && text && text[size - 1] == ' ')
	{
		i = 0;
		free(list[0]);
		while (size > 1 && text[size] && text[size] == ' ')
			size --;
		list[0] = malloc(sizeof(char) * (size + 1));
		list[0][size] = 0;
		while (i < size - 1 && text[i])
		{
			if (size == 0)
				break ;
			list[0][i] = text[i];
			i++;
		}
	}
	else if (size <= 0)
		list[0] = 0;
	else
		ft_strlcpy(list[0], text, ft_strlen(text) + 1);
}

static char	**ms_translate_params(t_params *main_params, char *cmd)
{
	int			len;
	int			i;
	char		**args;
	t_params	*param;

	param = main_params;
	i = 0;
	len = ms_get_nb_param(main_params);
	args = malloc(sizeof(char *) * (len + 2));
	args[len + 1] = 0;
	args[0] = cmd;
	while (param != NULL && ++i <= len)
	{
		if (param->text)
			args[i] = malloc(sizeof(char) * (ft_strlen(param->text) + 1));
		if (param->text && param->next != NULL)
			ft_strlcpy(args[i], param->text, ft_strlen(param->text) + 1);
		else if (param->text)
			ms_copy_without_end_space(&args[i], param->text,
				ft_strlen(param->text) - 1);
		else
			args[i] = NULL;
		param = param->next;
	}
	return (args);
}

void	ms_translate_to_cmd(t_cmd *cmd, t_pipes *main)
{
	t_pipes	*cpy_pipe;
	t_cmd	*cpy_cmd;

	cpy_pipe = main;
	cpy_cmd = cmd;
	while (cpy_pipe != NULL)
	{
		cpy_cmd->fd_out = -1;
		cpy_cmd->fd_in = -1;
		if (cpy_pipe->error != NO_ERROR)
			cpy_cmd->error_id = cpy_pipe->error;
		else
			cpy_cmd->error_id = cpy_pipe->command->error;
		cpy_cmd->args = ms_translate_params(cpy_pipe->command->params,
				ms_get_command(cpy_pipe->command));
		cpy_cmd->pid = 0;
		if (cpy_pipe->right)
			cpy_cmd->next = malloc(sizeof(*cpy_cmd));
		else
			cpy_cmd->next = NULL;
		ms_redirect_handler(cpy_cmd);
		if (cpy_cmd->next)
			cpy_cmd = cpy_cmd->next;
		cpy_pipe = cpy_pipe->right;
	}
}
