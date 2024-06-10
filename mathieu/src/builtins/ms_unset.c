/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mscheman@student.42angouleme.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 17:05:06 by mscheman          #+#    #+#             */
/*   Updated: 2024/05/01 17:05:06 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mnii_shlel.h>

static int	count_removed(char **envp, char **to_remove);
static bool	is_contained(char *str, char **tab);

int	builtin_unset(int argc, char **argv, char ***envp)
{
	int		i;
	int		j;
	int		m_size;
	char	**dup;

	if (argc == 1)
		return (EXIT_SUCCESS);
	m_size = tablen((*envp)) + 1;
	m_size -= count_removed((*envp), &argv[1]);
	dup = malloc(sizeof(char *) * m_size);
	i = 0;
	j = 0;
	while ((*envp)[i + 1])
	{
		if (is_contained((*envp)[i], &argv[1]) == true)
			i++;
		dup[j] = ft_strdup((*envp)[i]);
		i++;
		j++;
	}
	dup[j] = NULL;
	free_tab((void **)(*envp));
	(*envp) = dup;
	return (EXIT_SUCCESS);
}

static int	count_removed(char **envp, char **to_remove)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	while (envp[i])
	{
		count += is_contained(envp[i], to_remove);
		i++;
	}
	return (count);
}

static bool	is_contained(char *str, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_strncmp(str, tab[i], ft_strlen(str) + 1) == '=')
			return (true);
		i++;
	}
	return (false);
}