/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:26:56 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/17 16:29:04 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

static void	check(int argc, char **envp);
static void	error(int error);
static char	*get_pwd(void);
static void	update_envp(char **argv, char **envp, char *curr_pwd);

int	builtin_cd(int argc, char **argv, char **envp)
{
	char	*curr_pwd;

	check(argc, envp);
	curr_pwd = get_pwd();
	if (argc == 1)
		chdir(&envp_find(envp, "HOME")[6]);
	else if (chdir(argv[1]) != 0)
	{
		error(errno);
		free(curr_pwd);
		return (EXIT_FAILURE);
	}
	update_envp(argv, envp, curr_pwd);
	free(curr_pwd);
	return (EXIT_SUCCESS);
}

static void	check(int argc, char **envp)
{
	if (argc > 2)
	{
		error(-1);
		exit(EXIT_FAILURE);
	}
	if (argc == 1 && !envp_find(envp, "HOME"))
	{
		error(-2);
		exit(EXIT_FAILURE);
	}
}

static void	error(int error)
{
	if (error == -1)
		error_log("too many arguments\n");
	if (error == -2)
		error_log("cannot find HOME\n");
	if (error == ENOTDIR)
		error_log("path is not a directory\n");
	if (error == ENOENT)
		error_log("directory not found\n");
	if (error == EACCES)
		error_log("permission denied\n");
}

static char	*get_pwd(void)
{
	char	*path;

	path = getcwd(NULL, 0);
	return (path);
}

static void	update_envp(char **argv, char **envp, char *curr_pwd)
{
	char	*tmp;

	if (envp_find(envp, "PWD"))
	{
		tmp = malloc(sizeof(char) * (ft_strlen(argv[1]) + 5));
		ft_strlcpy(tmp, "PWD=", 5);
		ft_strlcat(tmp, argv[1], ft_strlen(argv[1]) + 5);
		tab_replace(envp, envp_find(envp, "PWD"), tmp);
	}
	if (envp_find(envp, "OLDPWD"))
	{
		tmp = malloc(sizeof(char) * (ft_strlen(curr_pwd) + 8));
		ft_strlcpy(tmp, "OLDPWD=", 8);
		ft_strlcat(tmp, argv[1], ft_strlen(curr_pwd) + 8);
		tab_replace(envp, envp_find(envp, "OLDPWD"), tmp);
	}
}
