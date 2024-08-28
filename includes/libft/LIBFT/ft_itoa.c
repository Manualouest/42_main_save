/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mscheman <mathieu.petru@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:11:34 by LeCoqBeau         #+#    #+#             */
/*   Updated: 2023/11/11 15:14:18 by mscheman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	absolute(int a);
static int	ft_getlen(int a);
static void	ft_invertstr(char *str);
static void	ft_numtostr(int a, char *str);

char	*ft_itoa(int a)
{
	char	*str;

	if (a == 0)
	{
		str = ft_strdup("0");
		return (str);
	}
	if (a == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	str = malloc(sizeof(char) * ft_getlen(a) + 1);
	if (!str)
		return (0);
	ft_numtostr(a, str);
	ft_invertstr(str);
	return (str);
}

static int	absolute(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

static int	ft_getlen(int a)
{
	int	i;

	i = 0;
	if (a < 0)
	{
		a = -a;
		i++;
	}
	while (a > 0)
	{
		a /= 10;
		i++;
	}
	return (i);
}

static void	ft_invertstr(char *str)
{
	int		i;
	int		len;
	char	c;

	i = 0;
	c = 0;
	len = ft_strlen(str);
	while (len / 2 > i)
	{
		c = str[i];
		str[i] = str[len - i - 1];
		str [len - i - 1] = c;
		i++;
	}
}

static void	ft_numtostr(int a, char *str)
{
	int	is_negative;
	int	copy;
	int	i;

	i = 0;
	is_negative = 0;
	if (a < 0)
		is_negative = 1;
	while (absolute(a) > 0)
	{
		copy = absolute(a) % 10;
		a /= 10;
		str[i] = copy + '0';
		i++;
	}
	if (is_negative)
		str[i++] = '-';
	str[i] = '\0';
}
