/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_heredoc_expand.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:57:19 by mbirou            #+#    #+#             */
/*   Updated: 2024/08/25 19:24:06 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

int	ms_should_expand_heredoc(char **delimiter)
{
	int		index;
	char	*tp_arg;
	int		do_expand;

	index = -1;
	do_expand = 1;
	while (delimiter[0][++index] && do_expand)
		if (delimiter[0][index] == -1 || delimiter[0][index] == -2)
			do_expand = 0;
	index = -1;
	while (delimiter[0] && delimiter[0][++index])
	{
		if (delimiter[0][index] < 7)
		{
			tp_arg = ms_tripple_join(ft_substr(delimiter[0], 0, index),
					&delimiter[0][index + 1], "", 100);
			free(delimiter[0]);
			delimiter[0] = tp_arg;
			index --;
		}
	}
	return (do_expand);
}

void	ms_insert_env(char **input, int i, int env_len, char **envp)
{
	char	*tp_str;
	char	*env_name;
	char	*envp_line;

	env_name = ft_substr(input[0], i + 1, env_len - 1);
	envp_line = envp_find(envp, env_name);
	if (envp_line)
		tp_str = ms_tripple_join(ft_substr(input[0], 0, i),
				&ft_strchr(envp_line, '=')[1],
				&input[0][i + env_len], 100);
	else
		tp_str = ms_tripple_join(ft_substr(input[0], 0, i),
				"", &input[0][i + env_len], 100);
	free(env_name);
	free(input[0]);
	input[0] = ft_strdup(tp_str);
	free(tp_str);
}

void	ms_do_heredoc_env(char **input, char **envp)
{
	int		i;
	int		env_len;

	i = -1;
	while (input[0][++i])
	{
		if (input[0][i] == '$')
		{
			env_len = 0;
			while (input[0][++env_len + i] && ft_isalnum(input[0][env_len + i]))
				;
			if (env_len == 1)
				continue ;
			ms_insert_env(input, i, env_len, envp);
			i = -1;
		}
	}
}
