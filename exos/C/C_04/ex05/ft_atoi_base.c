/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:27:00 by mbirou            #+#    #+#             */
/*   Updated: 2023/08/24 16:27:02 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	is_in_base(char num, char *base)
{
	int	pos;

	pos = 0;
	while (base[pos] != 0)
	{
		if (base[pos] == num)
			return (1);
		pos ++;
	}
	return (0);
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

int	ft_get_int(char *num, char *base, int len_base)
{
	int	temp;
	int	nb;
	int	pos;

	nb = 0;
	pos = 0;
	while (num[pos] != 0 && is_in_base(num[pos], base) == 1)
	{
		temp = 0;
		while (num[pos] != base[temp])
			temp ++;
		nb = temp + nb * len_base;
		pos ++;
	}
	return (nb);
}

int	ft_atoi_base(char *str, char *base)
{
	int	temp;
	int	sign;

	temp = 0;
	sign = 1;
	if (check_base(base) == 1)
	{
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
		return (sign * ft_get_int(&str[temp], base, ft_strlen(base)));
	}
	return (0);
}
