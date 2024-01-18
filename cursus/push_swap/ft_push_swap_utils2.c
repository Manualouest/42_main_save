/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:12:19 by mbirou            #+#    #+#             */
/*   Updated: 2024/01/18 19:12:04 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	ft_len_str_n(const char *s, int chc)
{
	int	i;

	i = 0;
	if (!s)
		return (chc * -1);
	if (chc == 0)
	{
		while (s[i] != 0)
		{
			i ++;
		}
		return (i);
	}
	return (-1);
}

char	*ft_strlcat(char *dest, char *src, int free_chc)
{
	int		i;
	int		len;
	char	*tp;

	i = 0;
	len = ft_len_str_n(dest, 0) + ft_len_str_n(src, 0);
	tp = (char *)ft_calloc(len + 1, 1);
	if (!tp)
		return (NULL);
	len = 0;
	while (dest && dest[i] != 0)
	{
		tp[i] = dest[i];
		i ++;
	}
	tp[i] = ' ';
	while (src && src[len] != 0)
	{
		tp[i + 1] = src[len];
		i++;
		len ++;
	}
	if (dest && free_chc == 1)
		free(dest);
	return (tp);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	i;

	i = 0;
	if (nmemb == 0 || size == 0)
	{
		array = malloc(1);
		((char *)array)[0] = 0;
		if (!array)
			return (NULL);
		return (array);
	}
	if ((nmemb >= 2147483647 || size >= 2147483647
			|| (nmemb * size > 2147483647)))
		return (0);
	array = malloc((size * nmemb) + 1);
	((char *)array)[size * nmemb] = 0;
	if (!array)
		return (NULL);
	while (i < nmemb * size)
	{
		((char *)array)[i] = 0;
		i ++;
	}
	return (array);
}

int	ft_is_sorted(t_stack *stk)
{
	int	last_num;

	if (stk)
	{
		last_num = stk->content;
		if (stk->next)
			stk = stk->next;
		while (stk && stk->next)
		{
			if (stk->content < last_num)
				return (0);
			last_num = stk->content;
			stk = stk->next;
		}
		if (stk && stk->content < last_num)
			return (0);
		return (1);
	}
	return (0);
}

int	ft_is_rsorted(t_stack *stk)
{
	int	last_num;

	if (stk)
	{
		last_num = stk->content;
		if (stk->next)
			stk = stk->next;
		while (stk && stk->next)
		{
			if (stk->content > last_num)
				return (0);
			last_num = stk->content;
			stk = stk->next;
		}
		if (stk && stk->content > last_num)
			return (0);
		return (1);
	}
	return (0);
}
