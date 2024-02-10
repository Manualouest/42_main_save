/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:12:12 by mbirou            #+#    #+#             */
/*   Updated: 2023/11/03 19:12:12 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "extras.h"

static int	get_num_len(int num);
static int	ft_abs(int num);
static char	*fill_num(char *dst, int num, int num_len);

char	*ft_itoa(int n)
{
	char	*num;
	int		len_num;

	len_num = get_num_len(n);
	num = malloc((len_num + 1) * sizeof(char));
	if (!num)
		return (NULL);
	num[len_num] = 0;
	num = fill_num(num, n, len_num - 1);
	return (num);
}

static char	*fill_num(char *dst, int num, int num_len)
{
	int	stop;

	stop = 0;
	if (num < 0)
	{
		dst[0] = '-';
		stop ++;
	}
	while (num_len >= stop)
	{
		dst[num_len] = ft_abs(num % 10) + '0';
		num_len --;
		num = num / 10;
	}
	return (dst);
}

static int	get_num_len(int num)
{
	int	i;

	i = 0;
	if (num <= 0)
		i ++;
	while (num != 0)
	{
		num = ft_abs(num / 10);
		i ++;
	}
	return (i);
}

static int	ft_abs(int num)
{
	if (num < 0)
		return (-(num));
	return (num);
}
