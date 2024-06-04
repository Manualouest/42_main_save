/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_tokeniser_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 17:11:46 by mbirou            #+#    #+#             */
/*   Updated: 2024/05/17 17:04:35 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

char	*ms_get_next_item(char *line, int *main_index)
{
	char	*item;
	int		start;
	int		type;
	int		i;

	i = *main_index;
	while (line[i] && line[i] == ' ')
		i ++;
	start = i;
	if (ft_isalnum(line[i]))
		type = STRING;
	else
		type = SYMBOL;
	while (line[i] && (type == ft_isalnum(line[i])))
		i ++;
	item = ft_substr(line, start, (i - start));
	*main_index = i;
	return (item);
}

int	ms_find_command(char *line, int *i, t_command *struct_command)
{
	char	*command;
	int		cmd;

	command = ms_get_next_item(line, i);
	if (ft_strncmp(command, "echo", 4) == 0)
		cmd = ECHO;
	else if (ft_strncmp(command, "cd", 2) == 0)
		cmd = CD;
	else if (ft_strncmp(command, "pwd", 3) == 0)
		cmd = PWD;
	else if (ft_strncmp(command, "export", 6) == 0)
		cmd = EXPORT;
	else if (ft_strncmp(command, "unset", 5) == 0)
		cmd = UNSET;
	else if (ft_strncmp(command, "env", 3) == 0)
		cmd = ENV;
	else if (ft_strncmp(command, "exit", 4) == 0)
		cmd = EXIT;
	else
		cmd = NO_CMD;
	struct_command->cmd = command;
	return (cmd);
}

int	ms_skip_echo_param(char *line, int *main_index)
{
	int	i;

	i = *main_index + 1;
	while (line[i] && line[i] == 'n')
	{
		write(1, &line[i], 1);
		i ++;
	}
	if (line[i] && line[i] != ' ')
		return (0);
	*main_index = i;
	return (1);
}

int	ms_check_for_echo_params(char *line, int *main_index)
{
	int	i;
	int	has_params;

	i = *main_index - 1;
	has_params = 0;
	while (line[++i])
	{
		if (line[i] == '-')
		{
			if (ms_skip_echo_param(line, &i) == 0)
				break ;
			else
				has_params = 1;
		}
		else if (line[i] != ' ')
			break ;
	}
	if (has_params)
		*main_index = i;
	return (has_params);
}

void	ms_init_cmd(t_command *command, char *line, int *i)
{
	int	tp_i;

	command->builtins = ms_find_command(line, i, command);
	command->params = malloc(sizeof(*command->params));
	command->params->quote_level = 0;
	command->has_option = 0;
	if (command->builtins == ECHO && ms_check_for_echo_params(line, i))
		command->has_option = 1;
	else
	{
		tp_i = *i;
		while (line[tp_i] == ' ')
			tp_i ++;
		*i = tp_i;
	}
	command->error = NO_ERROR;
	command->cmd_errno = 0;
}
