/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:02:02 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/18 00:59:59 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		i ++;
	}
	return (i);
}

int	check_base(char *base)
{
	int	temp1;
	int	temp2;
	int	check;

	temp1 = 0;
	while (base[temp1] != 0)
	{
		check = 0;
		temp2 = 0;
		while (base[temp2] != 0)
		{
			if (base[temp1] == base[temp2])
				check ++;
			temp2 ++;
		}
		if (check > 1 || base[temp1] == '+' || base[temp1] == '-'
			|| (base[temp1] >= 9 && base[temp1] <= 13)
			|| base[temp1] == ' ')
			return (0);
		temp1 ++;
	}
	if (temp1 < 2)
		return (0);
	else
		return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		len_base;
	char	nb;

	len_base = ft_strlen(base);
	if (check_base(base) == 1)
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			ft_putnbr_base((nbr / len_base) * -1, base);
			nb = base[(nbr % len_base) * -1];
			write (1, &nb, 1);
		}
		else if (nbr < len_base)
		{
			nb = base[nbr];
			write (1, &nb, 1);
		}
		else if (nbr >= len_base)
		{
			ft_putnbr_base(nbr / len_base, base);
			nb = base[nbr % len_base];
			write (1, &nb, 1);
		}
	}
}

int	sl_base_change(int nbr, char *base)
{
	int		tt;

	tt = 0;
	if (nbr < 4)
		tt = base[nbr] - '0';
	else if (nbr >= 4)
	{
		tt += sl_base_change(nbr / 4, base);
		tt = (tt * 10) + (base[nbr % 4] - '0');
	}
	return (tt);
}

int	ft_atoi(char *str)
{
	int	num;
	int	sign;
	int	temp;

	num = 0;
	sign = 1;
	temp = 0;
	while (str[temp] != 0 && (str[temp] == ' '
			|| (str[temp] >= 9 && str[temp] <= 13)))
		temp ++;
	while (str[temp] != 0
		&& (str[temp] == '+' || str[temp] == '-'))
	{
		if (str[temp] == '-')
			sign = sign * -1;
		temp ++;
	}
	while (str[temp] != 0 && (str[temp] >= '0' && str[temp] <= '9'))
		num = num * 10 + (str[temp++] - '0');
	return (num * sign);
}

void	ft_putnbr(int nb)
{
	int	temp;

	if (nb < 0)
	{
		write(1, "-", 1);
	}
	if (nb < 10 && nb > -10)
	{
		nb = nb + '0';
		if (nb - '0' < 0)
			nb = ((nb - '0') * -1) + '0';
		write(1, &nb, 1);
	}
	else
	{
		if (nb % 10 < 0)
			temp = (nb % 10) * -1 + '0';
		else
			temp = nb % 10 + '0';
		if (nb < 0)
			ft_putnbr((nb / 10) * -1);
		else
			ft_putnbr(nb / 10);
		write(1, &temp, 1);
	}
}

int	main(int argc, char **argv)
{
	int	test;

	ft_putnbr_base(ft_atoi(argv[1]), argv[2]);
	test = sl_base_change(ft_atoi(argv[1]), argv[2]);
	write(1, "\n", 1);
	ft_putnbr(test);
}
