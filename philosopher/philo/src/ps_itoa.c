/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:53:43 by mbirou            #+#    #+#             */
/*   Updated: 2024/05/18 02:04:09 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

static long int	ps_get_num_len(long int num);
static long int	ps_abs(long int num);
static char		*ps_fill_num(char *dst, long int num, long int num_len);

char	*ps_itoa(long int n)
{
	char		*num;
	long int	len_num;

	len_num = ps_get_num_len(n);
	num = malloc((len_num + 1) * sizeof(char));
	if (!num)
		return (NULL);
	num[len_num] = 0;
	num = ps_fill_num(num, n, len_num - 1);
	return (num);
}

static char	*ps_fill_num(char *dst, long int num, long int num_len)
{
	long int	stop;

	stop = 0;
	if (num < 0)
	{
		dst[0] = '-';
		stop ++;
	}
	while (num_len >= stop)
	{
		dst[num_len] = ps_abs(num % 10) + '0';
		num_len --;
		num = num / 10;
	}
	return (dst);
}

static long int	ps_get_num_len(long int num)
{
	long int	i;

	i = 0;
	if (num <= 0)
		i ++;
	while (num != 0)
	{
		num = ps_abs(num / 10);
		if (num == 10 || num == -10)
			i ++;
		i ++;
	}
	return (i);
}

static long int	ps_abs(long int num)
{
	if (num < 0)
		return (-(num));
	return (num);
}
