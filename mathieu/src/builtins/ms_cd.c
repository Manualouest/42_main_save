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

static int	check(int argc, char **envp);
static void	error(int error);
static void	update_envp(char ***envp, char *old_pwd, char *new_pwd);

int	builtin_cd(int argc, char **argv, char ***envp)

{
	char	*old_pwd;
	char	*new_pwd;

	if (check(argc, *envp))
		return (EXIT_FAILURE);
	if (argc == 1 && (chdir(&envp_find(*envp, "HOME")[6]) != 0))
	{
		error(errno);
		return (EXIT_FAILURE);
	}
	old_pwd = getcwd(NULL, 0);
	if (chdir(argv[1]) != 0)
	{
		error(errno);
		free(old_pwd);
		return (EXIT_FAILURE);
	}

	new_pwd = getcwd(NULL, 0);
	update_envp(envp, old_pwd, new_pwd);
	free(old_pwd);
	free(new_pwd);
	return (EXIT_SUCCESS);
}

static int	check(int argc, char **envp)
{
	if (argc > 2)
	{
		error(-1);
		return (EXIT_FAILURE);
	}
	if (argc == 1 && !envp_find(envp, "HOME"))
	{
		error(-2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static void	error(int error)
{
	if (error == -1)
		error_log("too many arguments", '\n');
	if (error == -2)
		error_log("cannot find HOME", '\n');
	if (error == ENOTDIR)
		error_log("path is not a directory", '\n');
	if (error == ENOENT)
		error_log("directory not found", '\n');
	if (error == EACCES)
		error_log("permission denied", '\n');
}

static void	update_envp(char ***envp, char *old_pwd, char *new_pwd)
{
	char	*tmp;

	if (envp_find((*envp), "PWD"))
	{
		tmp = malloc(sizeof(char) * (ft_strlen(old_pwd) + 8));
		ft_strlcpy(tmp, "OLDPWD=", 8);
		ft_strlcat(tmp, old_pwd, ft_strlen(old_pwd) + 8);
		if (envp_find((*envp), "OLDPWD"))
			tab_replace((*envp), envp_find((*envp), "OLDPWD"), tmp);
		else
			(*envp) = tab_append((*envp), tmp, -1);
	}
	tmp = malloc(sizeof(char) * (ft_strlen(new_pwd) + 5));
	ft_strlcpy(tmp, "PWD=", 5);
	ft_strlcat(tmp, new_pwd, ft_strlen(new_pwd) + 5);
	if (envp_find((*envp), "PWD"))
		tab_replace((*envp), envp_find((*envp), "PWD"), tmp);
	else
		(*envp) = tab_append((*envp), tmp, -1);
}
