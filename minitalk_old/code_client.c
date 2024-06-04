/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:52:19 by mbirou            #+#    #+#             */
/*   Updated: 2024/02/09 04:41:45 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_bit_confirm = 0;

void	ft_timer_switch(int sig)
{
	g_bit_confirm = sig;
}

void	ft_timer(void)
{
	int	time;

	time = 0;
	while (g_bit_confirm == 0)
	{
		if (time > 30000)
		{
			ft_send_error(0, 2);
			exit(1);
		}
		usleep(10);
		time += 10;
	}
	g_bit_confirm = 0;
	return ;
}

void	ft_send_sig(int pid, char c)
{
	int		bit;
	char	tp_c;

	bit = 0;
	while (++bit < 9)
	{
		tp_c = c >> (8 - bit);
		if ((tp_c & 1) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		ft_timer();
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3 || ft_has_letter(argv[1]))
		return (ft_send_error(argc, 1));
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, ft_timer_switch);
	i = -1;
	while (argv[2][++i] != 0)
		ft_send_sig(pid, argv[2][i]);
	ft_send_sig(pid, (char)0);
	return (0);
}
