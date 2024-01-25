/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:12:19 by mbirou            #+#    #+#             */
/*   Updated: 2023/12/19 03:34:59 by mbirou           ###   ########.fr       */
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

int	is_sorted(t_stack *stk)
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

int	is_rsorted(t_stack *stk)
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

int	find_index_min(t_stack *stk)
{
	int	index;
	int	curr_min;
	int	i;

	if (stk)
	{
		curr_min = stk->content;
		index = 0;
		i = 0;
		while (stk && stk->next != NULL)
		{
			if (stk->content < curr_min)
			{
				index = i;
				curr_min = stk->content;
			}
			i ++;
			stk = stk->next;
		}
		if (stk->content < curr_min)
			index = i;
		return (index);
	}
	return (-1);
}

int	find_index_max(t_stack *stk)
{
	int	index;
	int	curr_min;
	int	i;

	if (stk)
	{
		curr_min = stk->content;
		index = 0;
		i = 0;
		while (stk && stk->next != NULL)
		{
			if (stk->content > curr_min)
			{
				index = i;
				curr_min = stk->content;
			}
			i ++;
			stk = stk->next;
		}
		if (stk->content > curr_min)
			index = i;
		return (index);
	}
	return (-1);
}
