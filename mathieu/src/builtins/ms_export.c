/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:06:15 by mscheman          #+#    #+#             */
/*   Updated: 2024/06/10 17:53:40 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

static void	add_to_envp(char ***envp, char *to_add);
static char *find_similar(char **tab, char *cmp);
static int	check_args(const char *input);
static bool	is_validchar(char c);

int	builtin_export(int argc, char **argv, char ***envp)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (argc == 1)
	{
		builtin_export_noargs(*envp);
		return (EXIT_SUCCESS);
	}
	while (argv[++i])
	{
		if (!ft_strncmp("_=", argv[i], 2) || !ft_strncmp("_", argv[i], 2))
			continue ;
		if (check_args(argv[i]))
		{
			ret++;
			error_log("cannot export this variable");
			continue ;
		}
		add_to_envp(envp, ft_strdup(argv[i]));
	}
	if (ret != 0)
		ret = EXIT_FAILURE;
	return (ret);
}

static void	add_to_envp(char ***envp, char *to_add)
{
	char	*old;

	old = find_similar(*envp, to_add);
	if (!old)
		envp[0] = tab_append(envp[0], to_add, 0);
	else
		tab_replace(*envp, old, to_add);
}

static char *find_similar(char **tab, char *cmp)
{
	int	i;
	int	len;
	int	comp;

	i = 0;
	if (envp_find(tab, cmp))
		return (envp_find(tab, cmp));
	len = 0;
	while (cmp[len])
	{
		if (!cmp[len] || cmp[len] == '=')
			break ;
		len++;
	}
	if (cmp[len] == '=')
		len--;
	while (tab[i])
	{
		comp = ft_strncmp(tab[i], cmp, len);
		if (comp == '=' || comp == '=' * -1 || comp == 0)
			return (tab[i]);
		i++;
	}
	return (NULL);
}

static int	check_args(const char *input)
{
	int	i;

	if (input[0] != '_' && !ft_isalpha(input[0]))
		return (EXIT_FAILURE);
	i = 1;
	while (input[i] && input[i] != '=')
	{
		if (!is_validchar(input[i]))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static bool	is_validchar(char c)
{
	if (ft_isalnum(c) || c == '_' || c == '=')
		return (true);
	return (false);
}
