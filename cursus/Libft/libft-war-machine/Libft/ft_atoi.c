/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:07:11 by mbirou            #+#    #+#             */
/*   Updated: 2023/10/31 14:58:57 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	skip_spaces(const char *nptr);

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	i = skip_spaces(nptr);
	sign = 1;
	num = 0;
	if (nptr[i] == '-')
	{
		i ++;
		sign = -1;
	}
	if (nptr[i - 1] != '-' && nptr[i] == '+')
		i ++;
	while (nptr[i] != 0 && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		num = num * 10 + (nptr[i] - '0');
		i ++;
	}
	return (num * sign);
}

static int	skip_spaces(const char *nptr)
{
	int	i;

	i = 0;
	while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		&& nptr[i] != 0)
	{
		i ++;
	}
	return (i);
}
