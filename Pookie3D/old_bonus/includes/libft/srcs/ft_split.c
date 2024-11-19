/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xeo <xeo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 18:16:49 by mhaouas           #+#    #+#             */
/*   Updated: 2024/04/22 20:56:25 by xeo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

static void	free_all(char **buff, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(buff[i]);
		i++;
	}
	free(buff);
}

int	ft_count_word(char const *s, char sep)
{
	int	i;
	int	count;

	i = 0;
	if (!s)
		return (0);
	while (s[i] == sep)
		i++;
	if ((s[i] == 0))
		return (0);
	count = 1;
	while (s[i])
	{
		if ((s[i] == sep) && (s[i + 1] != sep) && (ft_isprint(s[i + 1]) == 1))
		{
			count += 1;
			i++;
		}
		else
			i++;
	}
	return (count);
}

static int	count_char(char *s, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while ((s[i] != sep) && s[i])
	{
		count++;
		i++;
	}
	return (count);
}

static char	**split_format(char **buff, char const *s, char sep)
{
	int	i;
	int	g;
	int	count;

	i = 0;
	g = 0;
	while (s[i])
	{
		while (s[i] == sep)
			i++;
		if (s[i] == '\0')
			break ;
		count = count_char((char *)s + i, sep);
		buff[g] = ft_substr(s, i, count);
		if (!buff[g])
		{
			free_all(buff, g);
			return (NULL);
		}
		i += count;
		g++;
	}
	buff[g] = NULL;
	return (buff);
}

char	**ft_split(char const *s, char sep)
{
	char	**buff;

	if (!s)
		return (NULL);
	buff = (char **)malloc(sizeof(char *) * (ft_count_word(s, sep) + 1));
	if (!buff)
		return (NULL);
	buff = split_format(buff, s, sep);
	return (buff);
}
