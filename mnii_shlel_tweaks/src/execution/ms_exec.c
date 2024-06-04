/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 14:33:15 by mscheman          #+#    #+#             */
/*   Updated: 2024/06/01 17:13:07 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

static void	exec_cmd(t_cmd *cmd, char **envp, t_env_handler *path);
static void	correct_args(t_cmd *cmd, char *replace);
static void	get_path(t_cmd *cmd, t_env_handler *path);

//void	print_cmd(t_cmd *cmd)
//{
//	printf("- %s\n", cmd->args[0]);
//	int i = 1;
//	printf("\targs:");
//	while (cmd->args[i])
//		printf(" %s", cmd->args[i++]);
//	printf("\n\tfd_in: %d\n", cmd->fd_in);
//	printf("\tfd_out: %d\n", cmd->fd_out);
//}

void	ms_exec(t_cmd *to_exec, char **envp, t_env_handler *path)
{
	t_cmd	*cmd;
	int		edge[2];

	cmd = to_exec;
	cmd_iter(cmd, ms_exec_initfds);
	edge[0] = open("infile", O_RDONLY | O_CREAT);
	edge[1] = open("outfile", O_WRONLY | O_CREAT);
	ms_exec_redirectupdate(cmd, edge[0], edge[1]);
	while (cmd)
	{
		exec_cmd(cmd, envp, path);
		close(cmd->fd_in);
		close(cmd->fd_out);
		cmd = cmd->next;
	}
	ms_exec_closefds(to_exec);
	waitpid(-1, NULL, 0);
}

static void	exec_cmd(t_cmd *cmd, char **envp, t_env_handler *path)
{
	if (!cmd)
		return ;
	cmd->pid = fork();
	if (cmd->pid == 0)
	{
		get_path(cmd, path);
		dup2(cmd->fd_in, STDIN_FILENO);
		dup2(cmd->fd_out, STDOUT_FILENO);
		ms_exec_closefds(cmd);
		execve(cmd->args[0], cmd->args, envp);
	}
}

static void	get_path(t_cmd *cmd, t_env_handler *path)
{
	char	**split_path;
	char	*work;
	int		i;

	correct_args(cmd, NULL);
	split_path = ft_split(path->info.content, ':');
	i = 0;
	while (split_path[i])
	{
		work = ft_strjoin(split_path[i], cmd->args[0]);
		if (!access(work, X_OK))
			break ;
		free(work);
		work = NULL;
		i++;
	}
	correct_args(cmd, work);
	free_tab((void **)split_path);
}

static void	correct_args(t_cmd *cmd, char *replace)
{
	char	*tmp;

	tmp = NULL;
	if (replace)
	{
		free(cmd->args[0]);
		cmd->args[0] = replace;
		return ;
	}
	if (cmd->args[0][0] == '/')
		return ;
	tmp = ft_calloc(sizeof(char), (ft_strlen(cmd->args[0]) + 2));
	tmp[0] = '/';
	ft_strlcat(tmp, cmd->args[0], ft_strlen(cmd->args[0]) + 2);
	free(cmd->args[0]);
	cmd->args[0] = tmp;
}
