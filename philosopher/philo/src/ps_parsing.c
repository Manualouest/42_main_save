/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:53:54 by mbirou            #+#    #+#             */
/*   Updated: 2024/07/01 11:32:37 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

void	ps_write_errors(int errors)
{
	write(2, "Error\n", 6);
	if ((errors >> 4) & 1)
		write(2, "Invalid number of philosophers.\n", 32);
	if ((errors >> 3) & 1)
		write(2, "Invalid time to die.\n", 21);
	if ((errors >> 2) & 1)
		write(2, "Invalid time to eat.\n", 21);
	if ((errors >> 1) & 1)
		write(2, "Invalid time to sleep.\n", 23);
	if ((errors >> 0) & 1)
		write(2, "Invalid number of meals.\n", 25);
}

int	ps_input_parsing(int nb_params, char **params)
{
	int	errors;

	errors = 0;
	if (nb_params < 5 || nb_params > 6)
	{
		write(2, "Error\nInvalid number of parameters.\n", 36);
		return (0);
	}
	if (ps_atoi(params[1]) < 1)
		errors = ((errors >> 4) + 1) << 4;
	if (ps_atoi(params[2]) < 0 || ps_atoi(params[2]) > 2147483647)
		errors = ((errors >> 3) + 1) << 3;
	if (ps_atoi(params[3]) < 0 || ps_atoi(params[3]) > 2147483647)
		errors = ((errors >> 2) + 1) << 2;
	if (ps_atoi(params[4]) < 0 || ps_atoi(params[4]) > 2147483647)
		errors = ((errors >> 1) + 1) << 1;
	if (nb_params == 6 && (ps_atoi(params[5]) < 1
			|| ps_atoi(params[5]) > 2147483647))
		errors = ((errors >> 0) + 1) << 0;
	if (errors == 0)
		return (1);
	ps_write_errors(errors);
	return (0);
}

int	ps_are_mutexs_good(t_mutex *mutexs, t_philos *philos)
{
	if (mutexs && mutexs->wl_safety != 0)
		return (0);
	while (philos && !philos->sc_safety && philos->my_fork
		&& !philos->my_fork->f_safety)
		philos = philos->next;
	if (!philos)
		return (1);
	return (0);
}
