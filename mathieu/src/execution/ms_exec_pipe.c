/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 18:33:01 by mscheman          #+#    #+#             */
/*   Updated: 2024/06/12 14:33:04 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

static void	wait_childs(t_cmd *childs);
static char	*try_path(t_cmd *cmd, char *env_path);

void	ms_exec_pipe(t_cmd *to_exec, char **env)
{
	t_cmd	*first;

	first = to_exec->first;
	if (ms_setup_pipes(to_exec))
	{
		error_log("couldnt setup the pipes");
		return ;
	}
	while (to_exec)
	{
		child_exec(to_exec, env);
		to_exec = to_exec->next;
	}
	ms_exec_closefds(to_exec);
	wait_childs(first);
	cmd_clear(&to_exec, free_tab);
}

void	ms_child_getpath(t_cmd *cmd, char *env_path)
{
	char	*expected_path;

	if (!env_path || cmd->args[0][0] == '/'
		|| !ft_strncmp(cmd->args[0], "./", 2)
		|| !ft_strncmp(cmd->args[0], "../", 3))
		return ;
	expected_path = try_path(cmd, env_path);
	if (!expected_path)
		return ;
	free(cmd->args[0]);
	cmd->args[0] = expected_path; 
}

static void	wait_childs(t_cmd *childs)
{
	int	status;

	while (childs)
	{
		if (!ms_is_builtin(childs))
		{
			waitpid(childs->pid, &status, 0);
			if (WIFEXITED(status))
				g_signal = WEXITSTATUS(status);
		}
		childs = childs->next;
	}
}

static char	*try_path(t_cmd *cmd, char *env_path)
{
	int		i;
	int		final_len;
	char	*tmp;
	char	**tab_path;


	i = 0;
	tab_path= ft_split(env_path, ':');
	while (tab_path[i])
	{
		final_len = ft_strlen(tab_path[i]) + ft_strlen(cmd->args[0]) + 2;
		tmp = malloc(sizeof(char) * final_len);
		ft_strlcpy(tmp, tab_path[i], final_len);
		ft_strlcat(tmp, "/", final_len);
		ft_strlcat(tmp, cmd->args[0], final_len);
		if (access(tmp, X_OK) == 0)
			break ;
		free(tmp);
		tmp = NULL;
		i++;
	}
	free_tab((void **)tab_path);
	return (tmp);
}
