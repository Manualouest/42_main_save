/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 11:02:02 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/24 13:34:51 by mbirou           ###   ########.fr       */
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
