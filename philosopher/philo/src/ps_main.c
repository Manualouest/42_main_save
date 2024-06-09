/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:45:54 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/09 21:11:25 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

#include <stdio.h>

int	main(int argc, char **argv)
{
	int			*inputs;
	t_mutex		*mutexs;
	t_philos	*philos;

	if (!ps_input_parsing(argc, argv))
		return (0);
	inputs = ps_setup_inputs(argc, argv);
	mutexs = ps_setup_mutexs();
	if (!inputs || !mutexs)
		philos = NULL;
	else
		philos = ps_setup_philos(inputs, mutexs);
	if (!inputs || !mutexs || !philos || !ps_are_mutexs_good(mutexs, philos))
	{
		write(1, "Error\n", 6);
		if (!inputs || !mutexs || !philos)
			write(1, "Shutdown, a malloc has failed.\n", 31);
		else
			write(1, "Shutdown, a mutex has failed.\n", 30);
		ps_free(inputs, mutexs, philos);
		return (0);
	}
	ps_init_philos(philos, inputs[0]);
	ps_free(inputs, mutexs, philos);
}
