/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_server_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:55:46 by mbirou            #+#    #+#             */
/*   Updated: 2024/07/04 13:31:18 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_bit_info	g_bit_info;

void	ft_start_writer(int pid)
{
	write(1, "\nMessage received from ", 23);
	ft_putnbr(pid);
	write(1, ": ", 2);
}

void	ft_end_writer(char *string)
{
	write(1, string, ft_strlen(string));
	free(string);
}

void	ft_handler(int sig, siginfo_t *info, void *oldact)
{
	(void)oldact;
	g_bit_info.car = g_bit_info.car << 1;
	if (sig == SIGUSR2)
		g_bit_info.car++;
	g_bit_info.bits++;
	if (g_bit_info.car == 0 && g_bit_info.bits == 8)
		kill(info->si_pid, SIGUSR2);
	if (g_bit_info.is_start == 0)
	{
		g_bit_info.str = malloc(1);
		g_bit_info.str[0] = 0;
		ft_start_writer(info->si_pid);
		g_bit_info.is_start++ ;
	}
	if (g_bit_info.bits == 8)
	{
		if (g_bit_info.car == 0 && --g_bit_info.is_start == 0)
			ft_end_writer(g_bit_info.str);
		else
			g_bit_info.str = ft_strjoin(g_bit_info.str, (char)g_bit_info.car);
		g_bit_info.bits = 0;
		g_bit_info.car = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	if (argc != 1)
		return (ft_send_error(argc, 0));
	(void)argv;
	write(1, "Server pid: ", 12);
	ft_putnbr(getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &ft_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1 == 1)
		pause();
	return (0);
}
