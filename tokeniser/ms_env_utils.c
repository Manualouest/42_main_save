/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 18:55:42 by mbirou            #+#    #+#             */
/*   Updated: 2024/08/25 18:58:30 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <tokeniser.h>

char	*ms_find_env_name(char *content, char **envp)
{
	int		i;
	int		content_len;
	char	*tp_char;

	i = 0;
	tp_char = ft_substr(content, 2, ft_strlen(content) - 3);
	while (envp[i])
	{
		content_len = -1;
		while (envp[i] && envp[i][++content_len] && envp[i][content_len] != '=')
			;
		if (ft_strncmp(&envp[i][content_len + 1], tp_char,
			ft_strlen(tp_char)) == 0
			&& ft_strlen(tp_char) == ft_strlen(envp[i]) - content_len - 1)
		{
			free(tp_char);
			return (ft_substr(envp[i], 0, content_len));
		}
		i++;
	}
	free(tp_char);
	return (NULL);
}
