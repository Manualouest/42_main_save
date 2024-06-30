/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_quit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 20:02:29 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/24 20:02:29 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

void	ms_execve_quit(t_cmd *cmd, char **env)
{
	char		*err_msg;
	int 		err_code;
	struct stat	stat_var;

	err_code = errno;
	err_msg = strerror(err_code);
	if (err_code == ENOENT && !ft_strchr(cmd->args[0], '/'))
		err_msg = ERR_CMD_NOT_FOUND;
	if (err_code == EACCES)
	{
		if (stat(cmd->args[0], &stat_var) == -1)
			perror("mnii shlel: stat");
		if ((stat_var.st_mode & S_IFMT) == S_IFDIR)
			err_msg = ERR_ISDIR;
	}
	error_log("mnii shlel:", ' ');
	if (cmd->args[0][0])
		error_log(cmd->args[0], ' ');
	error_log(err_msg, '\n');
	ms_exec_unleak(cmd, env);
	if (err_code == ENOENT)
		exit(127);
	if (err_code == EACCES)
		exit(126);
	exit(EXIT_FAILURE);
}

void	ms_dup2_quit(t_cmd *cmd, char **env)
{
	error_log(ERR_DUP2, '\n');
	ms_exec_closefds(cmd->first);
	ms_exec_unleak(cmd, env);
	exit(EXIT_FAILURE);
}

void	ms_exec_unleak(t_cmd *cmd, char **env)
{
	free_tab((void **)env);
	ms_free_cmd(cmd->first);
	rl_clear_history();
}
