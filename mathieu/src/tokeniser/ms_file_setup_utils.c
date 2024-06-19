/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_file_setup_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:59:36 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/19 21:03:14 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

int	ms_is_file_real(char *filename)
{
	DIR	*dir;
	int	fd;

	if (!filename)
		return (-2);
	dir = opendir(filename);
	if (dir)
	{
		closedir(dir);
		return (-1);
	}
	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

static void	ms_do_separation(t_cmd *cmd, int *len, int *i)
{
	char	*tp_char;

	if ((*len > 0 && (cmd->args[*i][*len - 1] == '<'
			|| cmd->args[*i][*len - 1] == '>'))
			|| (cmd->args[*i][*len] == '<' || cmd->args[*i][*len] == '>'))
	{
		cmd->args = tab_append(cmd->args,
				ft_substr(cmd->args[*i], 0, *len), *i);
		*i = *i + 1;
		tp_char = ft_substr(cmd->args[*i], *len, ft_strlen(cmd->args[*i]));
		free(cmd->args[*i]);
		cmd->args[*i] = tp_char;
		*len = 0;
	}
}

void	ms_separate_symbols_base(t_cmd *cmd)
{
	int		i;
	int		len;
	t_cmd	*cpy_cmd;

	cpy_cmd = cmd;
	while (cpy_cmd)
	{
		i = -1;
		while (cpy_cmd->args[i + (i == -1)] && cpy_cmd->args[++i]
			&& cpy_cmd->args[i][0] != -1 && cpy_cmd->args[i][0] != -2)
		{
			len = -1;
			while (cpy_cmd->args[i] && cpy_cmd->args[i][++len])
			{
				if ((len == 0 || (len == 1 && (cpy_cmd->args[i][len - 1] == '<'
							|| cpy_cmd->args[i][len - 1] == '>')))
					&& (cpy_cmd->args[i][len] == '<'
						|| cpy_cmd->args[i][len] == '>'))
					continue ;
				ms_do_separation(cpy_cmd, &len, &i);
			}
		}
		cpy_cmd = cpy_cmd->next;
	}
}

char	**ms_remove_filename(char **args, int elem_index)
{
	int		index;
	char	**nargs;

	index = -1;
	nargs = ft_calloc(sizeof(char *), tablen(args) - 1);
	while (args[++index])
	{
		if (index != elem_index && index != elem_index + 1)
			nargs[index - ((index > elem_index) * 2)] = args[index];
		else
			free(args[index]);
	}
	free(args);
	return (nargs);
}

int	ms_opens(t_cmd *cmd, char *filename, int is_created, int kind)
{
	if (kind)
	{
		if (!is_created)
			return (open(filename, O_CREAT | O_APPEND, S_IRWXU));
		else if (is_created)
			return (open(filename, O_APPEND));
		else
			cmd->error_id = BAD_FILE;
		return (-1);
	}
	else if (!kind)
	{
		if (!is_created)
			return (open(filename, O_CREAT | O_WRONLY, S_IRWXU));
		else if (is_created)
			return (open(filename, O_WRONLY));
		else
			cmd->error_id = BAD_FILE;
		return (-1);
	}
	if (is_created)
		return (open(filename, O_RDONLY));
	else
		cmd->error_id = BAD_FILE;
	return (-1);
}
