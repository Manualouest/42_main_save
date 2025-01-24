/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 19:20:52 by mhaouas           #+#    #+#             */
/*   Updated: 2024/05/05 14:02:36 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	nb_count(int nb)
{
	if (nb == 0)
		return (1);
	return (nb_count(nb / 10) + 1);
}

static char	*buff_format(char *str, unsigned int size, int nb)
{
	unsigned int	g;

	g = 0;
	while (g < size)
	{
		str[size - g - 1] = (nb % 10) + '0';
		nb = nb / 10;
		g++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*buff;
	int		count;
	int		sign;
	int		nb;

	nb = n;
	sign = 0;
	count = nb_count(n) - 1;
	if (n < 0)
	{
		sign = 1;
		nb *= -1;
	}
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	buff = (char *)malloc(sizeof(char) * (count + 1 + sign));
	if (!buff)
		return (NULL);
	buff = buff_format(buff, count + sign, nb);
	if (sign == 1)
		buff[0] = '-';
	buff[count + sign] = '\0';
	return (buff);
}
