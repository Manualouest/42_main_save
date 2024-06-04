/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:06:24 by mbirou            #+#    #+#             */
/*   Updated: 2024/05/20 20:20:11 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_send_error(int check1, int check2)
{
	if ((check2 == 1 && check1 != 3) || (check2 == 0 && check1 != 1))
		write(2, "Wrong number of parameters.\n", 28);
	else if (check2 == 1)
		write(2, "Bad pid.\n", 9);
	else if (check2 == 2)
		write(2, "Server never gave response\n", 27);
	return (0);
}

int	ft_has_letter(char *str)
{
	int	i;

	i = -1;
	if (!str || str[0] == '\0')
		return (1);
	while (str[++i])
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (nptr[i] != 0 && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		num = num * 10 + (nptr[i] - '0');
		i ++;
	}
	return (num);
}

void	ft_putnbr(int n)
{
	unsigned int	temp;
	char			num;

	if (n < 0)
	{
		write(1, "-", 1);
		temp = n * -1;
	}
	else
		temp = n;
	if (temp > 9)
	{
		ft_putnbr(temp / 10);
	}
	num = temp % 10 + '0';
	write(1, &num, 1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != 0)
		i ++;
	return (i);
}
