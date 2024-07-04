/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 16:50:24 by mbirou            #+#    #+#             */
/*   Updated: 2024/07/01 09:29:33 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

void	ps_free(int *inputs, t_mutex *mutexs, t_philos *philos)
{
	t_philos	*p_next;

	if (inputs)
		free(inputs);
	if (mutexs)
	{
		if (!mutexs->wl_safety)
			pthread_mutex_destroy(&mutexs->writing_lock);
		free(mutexs);
	}
	while (philos)
	{
		if (!philos->sc_safety)
			pthread_mutex_destroy(&philos->status_check);
		if (philos->my_fork)
		{
			if (!philos->my_fork->f_safety)
				pthread_mutex_destroy(&philos->my_fork->fork);
			free(philos->my_fork);
		}
		p_next = philos->next;
		free(philos);
		philos = p_next;
	}
}
