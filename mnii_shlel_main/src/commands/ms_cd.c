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

static void	update_oldpwd(t_env_handler *env);
static void	update_pwd(t_env_handler *env);

void	ms_cd(char *param, t_env_handler *env)
{
	if (!*param)
	{
		if (env_find(env, "HOME") == NULL)
			return ;
		ms_cd(env_find(env, "HOME")->info.content, env);
		return ;
	}
	if (chdir(param) != 0)
		return ;
	update_oldpwd(env);
	update_pwd(env);
}

static void	update_oldpwd(t_env_handler *env)
{
	t_env_handler	*oldpwd;
	t_env_handler	*currpwd;
	t_env_handler	*tmp;
	char			*work;

	oldpwd = env_find(env, "OLDPWD");
	currpwd = env_find(env, "PWD");
	work = ft_calloc(ft_strlen(currpwd->info.content) + 7, sizeof(char));
	ft_strlcpy(work, "OLDPWD", 7);
	ft_strlcat(work, currpwd->info.content,
		7 + ft_strlen(currpwd->info.content));
	tmp = env_new(ms_string_to_env(work, 6));
	free(work);
	env_replace(&env, tmp, oldpwd);
	envdelone(oldpwd, free);
}

static void	update_pwd(t_env_handler *env)
{
	t_env_handler	*old_pwd;
	t_env_handler	*new_pwd;
	char			*work;
	char			*path;
	int				i;

	i = 0;
	path = NULL;
	while (path == NULL)
	{
		i++;
		path = getcwd(NULL, i);
	}
	work = ft_calloc(ft_strlen(path) + 4 + 1, sizeof(char));
	ft_strlcpy(work, "PWD", 4);
	ft_strlcat(work, path, ft_strlen(path) + 4 + 1);
	new_pwd = env_new(ms_string_to_env(work, 3));
	old_pwd = env_find(env, "PWD");
	env_replace(&env, new_pwd, old_pwd);
	envdelone(old_pwd, free);
	free(path);
	free(work);
}
