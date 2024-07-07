/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export_noarg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 14:50:38 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/06 14:50:38 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

static void	sort_envp(char **new_envp);
static void	print_env(int fd, char **env);
static void print_export_format(int fd, char *str1, char *str2);

int	builtin_export_noargs(t_cmd *cmd, char **envp)
{
	char	**dup_envp;

	dup_envp = tab_clone(envp);
	sort_envp(dup_envp);
	print_env(cmd->fd_out, dup_envp);
	free_tab((void **)dup_envp);
	return (EXIT_SUCCESS);
}

static void	sort_envp(char **new_envp)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	while (new_envp[i + 1])
	{
		len = ft_strlen(new_envp[i]);
		if (ft_strlen(new_envp[i + 1]) > (size_t)len)
			len = ft_strlen(new_envp[i + 1]);
		if (ft_strncmp(new_envp[i], new_envp[i + 1], len) > 0)
		{
			tmp = new_envp[i];
			new_envp[i] = new_envp[i + 1];
			new_envp[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}

static void	print_env(int fd, char **env)
{
	int	i;
	int	equal;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "_=", 2) == 0)
			i++;
		if (!env[i])
			return;
		equal = ft_strfind(env[i], '=');
		if (equal == (int)ft_strlen(env[i]))
			print_export_format(fd, env[i], NULL);
		else
		{
			env[i][equal] = 0;
			print_export_format(fd, env[i],  &env[i][equal + 1]);
			env[i][equal] = '=';
		}
		i++;
	}
}

static void print_export_format(int fd, char *str1, char *str2)
{
	ft_putstr_fd("declare -x ", fd);
	ft_putstr_fd(str1, fd);
	if (!str2)
		return ;
	ft_putstr_fd("=\"", fd);
	ft_putstr_fd(str2, fd);
	ft_putstr_fd("\"\n", fd);
}
