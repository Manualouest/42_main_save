/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_builtins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 19:11:08 by mscheman          #+#    #+#             */
/*   Updated: 2024/06/12 13:49:20 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

int	ms_exec_builtin(t_cmd *to_exec, char **env)
{
	int	ret;

	ret = -1;
	if (ft_strncmp(to_exec->args[0], "cd", 3) == 0)
		ret = builtin_cd(tablen(to_exec->args), to_exec->args, env);
	if (ft_strncmp(to_exec->args[0], "echo", 5) == 0)
		ret = builtin_echo(to_exec->args);
	if (ft_strncmp(to_exec->args[0], "env", 4) == 0)
		ret = builtin_env(env);
	if (ft_strncmp(to_exec->args[0], "pwd", 4) == 0)
		ret = builtin_pwd();
	if (ft_strncmp(to_exec->args[0], "exit", 5) == 0)
		ret = builtin_exit(to_exec->first, tablen(to_exec->args), to_exec->args, env);
	if (ft_strncmp(to_exec->args[0], "unset", 6) == 0)
		ret = builtin_unset(tablen(to_exec->args), to_exec->args, &env);
	if (ft_strncmp(to_exec->args[0], "export", 7) == 0)
		ret = builtin_export(tablen(to_exec->args), to_exec->args, &env);
	return (ret);
}