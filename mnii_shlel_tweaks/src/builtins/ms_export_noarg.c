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

static void	print_env(char **env);
static int	find_equal(const char *str);
static void	sort_envp(char **new_envp);

int	builtin_export_noargs(char **envp)
{
	char	**dup_envp;

	dup_envp = tab_clone(envp);
	sort_envp(dup_envp);
	print_env(dup_envp);
	free_tab((void **)dup_envp);
	return (EXIT_SUCCESS);
}

static void	print_env(char **env)
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
		equal = find_equal(env[i]);
		if (equal == (int)ft_strlen(env[i]))
			printf("declare -x %s\n", env[i]);
		else
		{
			env[i][equal] = 0;
			printf("declare -x %s=\"%s\"\n", env[i], &env[i][equal + 1]);
			env[i][equal] = '=';
		}
		i++;
	}
}

static int find_equal(const char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	return (i);
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
