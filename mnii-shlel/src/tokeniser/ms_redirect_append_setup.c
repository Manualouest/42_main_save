/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_redirect_append_setup.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 22:38:56 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/18 18:34:50 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

int	ms_is_file_real(char *filename)
{
	DIR	*dir;
	int	fd;

	dir = opendir(filename);
	if (dir)
	{
		closedir(dir);
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd != -1)
	{
		close(fd);
		return (1);
	}
	return (0);
}

void	ms_separate_symbols(t_cmd *cmd, t_cmd *start)
{
	char	*tp_char;
	int		i;
	int		len;

	while (cmd)
	{
		i = -1;
		while (cmd->args[i + (i == -1)] && cmd->args[++i])
		{
			len = -1;
			while (cmd->args[i] && cmd->args[i][++len])
			{
				if ((len == 0 || (len == 1 && (cmd->args[i][len - 1] == '<'
							|| cmd->args[i][len - 1] == '>')))
					&& (cmd->args[i][len] == '<' || cmd->args[i][len] == '>'))
					continue ;
				if ((len > 0 && (cmd->args[i][len - 1] == '<'
						|| cmd->args[i][len - 1] == '>'))
					|| (len > 0 && (cmd->args[i][len] == '<'
						|| cmd->args[i][len] == '>')))
				{
					cmd->args = tab_append(cmd->args, ft_substr(cmd->args[i], 0, len), i); // - 1
					i ++;
					tp_char = ft_substr(cmd->args[i], len, ft_strlen(cmd->args[i]));
					free(cmd->args[i]);
					cmd->args[i] = tp_char;
					len = 0;
				}
			}
		}
		cmd = cmd->next;
	}
	cmd = start;
}
// echo > test0 >test1 > test2> >test3>test4>test5
void	ms_redirect_append_setup(t_cmd *cmd)
{
	ms_separate_symbols(cmd, cmd);
}
