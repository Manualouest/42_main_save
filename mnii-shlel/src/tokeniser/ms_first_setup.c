/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_first_setup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:03:47 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/27 13:58:11 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

int	ms_nb_params(char *line, int index, int *line_index)
{
	int	nb_params;
	int	quote_level;

	nb_params = 0;
	quote_level = 0;
	while (line[++index] && line[index] == ' ')
		;
	*line_index = index - 1;
	while (line[index])
	{
		quote_level = ms_change_quote_level(line, index, quote_level);
		if (line[index] == ' ' && quote_level == 0)
		{
			while (line[++index] && line[index] == ' ')
				;
			if (line[index] && line[index] != ' ')
				nb_params ++;
		}
		else
			index ++;
	}
	return (nb_params);
}

int	ms_get_cut_len(char *line, int index, int index_save,
		int *cut_len)
{
	int	len;
	int	quote_level;

	len = 0;
	quote_level = 0;
	while (line[index] && line[index] == ' ')
		index ++;
	index_save = index;
	if (index >= (int)ft_strlen(line))
		return (-1);
	while (line[index])
	{
		quote_level = ms_change_quote_level(line, index, quote_level);
		if ((line[index] == ' ' || line[index] == '|') && quote_level == 0)
			break ;
		else
		{
			len ++;
			index ++;
		}
	}
	*cut_len = len;
	return (index_save);
}

char	**ms_cut_text(char *line)
{
	int		line_index;
	int		cut_len;
	char	**args;
	int		args_index;
	int		max_args;

	line_index = -1;
	args_index = -1;
	cut_len = 0;
	max_args = ms_nb_params(line, -1, &line_index);
	args = ft_calloc(sizeof(char *), (max_args + 3));
	if (!args)
		return (NULL);
	args[max_args + 1] = 0;
	while (line_index < (int)ft_strlen(line) && line[++line_index])
	{
		line_index = ms_get_cut_len(line, line_index, line_index, &cut_len);
		if (line_index == -1)
			break ;
		args[++args_index] = ft_substr(line, line_index, cut_len);
		line_index += cut_len;
	}
	free(line);
	return (args);
}

void	ms_misc_params_setup(t_cmd *cmd, t_cmd *first_cmd)
{
	cmd->fd_in = 0;
	cmd->fd_out = 1;
	cmd->error_id = NO_ERROR;
	cmd->first = first_cmd;
}

void	ms_base_setup(t_cmd *cmd, char *line)
{
	t_cmd	*cpy;
	int		old_index;
	int		index;

	cpy = cmd;
	index = 0;
	while (cpy)
	{
		ms_misc_params_setup(cpy, cmd);
		old_index = index;
		cpy->args = ms_cut_text(ft_substr(line, old_index,
					ms_go_to_pipe(line, &index) - old_index));
		if (line[index] == '|')
		{
			cpy->next = malloc(sizeof(*cpy->next));
			if (!cpy->next)
				ms_free_cmd(cmd);
			if (!cmd)
				return ;
			index ++;
		}
		else
			cpy->next = NULL;
		cpy = cpy->next;
	}
}
