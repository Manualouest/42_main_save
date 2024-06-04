/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_overseer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:43:52 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/04 20:25:35 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

void	ps_join_threads(t_philos *philos)
{
	int	broken_loop;

	broken_loop = philos->safety;
	if (broken_loop >= 0)
	{
		if (broken_loop > 0)
			write(2, "Shutdown, error during further thread creation.\n", 48);
		while (--broken_loop >= 0 && philos != NULL)
		{
			if (pthread_join(philos->philo, NULL) != 0)
				write(2, "Thread join failed.\n", 20);
			philos = philos->next;
		}
	}
	else
	{
		while (philos != NULL)
		{
			if (pthread_join(philos->philo, NULL) != 0)
				write(2, "Thread join failed.\n", 20);
			philos = philos->next;
		}
	}
}

void	ps_overseer_loop(t_philos *philos, int *stop, int nb_philos)
{
	t_philos	*cpy_philos;
	int			can_stop;

	cpy_philos = philos;
	can_stop = 0;
	if (pthread_mutex_lock(&cpy_philos->mutex->) != 0)
		*stop = 0;
	while (cpy_philos->stats && cpy_philos->stats->status != DEAD
		&& *stop == 1 && philos->safety < 0)
	{
		if (cpy_philos->stats->nb_meals_left == 0)
			can_stop ++;
		else
			can_stop = 0;
		pthread_mutex_unlock(&cpy_philos->stats->status_check);
		if (cpy_philos->next)
			cpy_philos = cpy_philos->next;
		else
			cpy_philos = philos;
		usleep(5);
		if (pthread_mutex_lock(&cpy_philos->stats->status_check) != 0)
			*stop = 0;
		if (can_stop == nb_philos + 1)
			break ;
	}
	*stop = 0;
	pthread_mutex_unlock(&cpy_philos->stats->status_check);
	cpy_philos = philos;
	ps_join_threads(cpy_philos);
}

void	ps_check_mutex_errors(t_philos *philos)
{
	t_philos	*cpy_philos;

	cpy_philos = philos;
	philos->mutex_stop = 0;
	while (cpy_philos != NULL && philos->mutex_stop == 0)
	{
		if (cpy_philos && (!cpy_philos->stats || !cpy_philos->fork))
		{
			write(2, "Malloc failed.\n", 15);
			philos->mutex_stop = 1;
		}
		if ((cpy_philos->mutex && (cpy_philos->mutex->cp_safety != 0
					|| cpy_philos->mutex->wp_safety != 0))
			|| (cpy_philos->fork && cpy_philos->fork->mt_safety != 0)
			|| (cpy_philos->stats && cpy_philos->stats->sc_safety != 0))
		{
			write(2, "Mutex failed.\n", 14);
			philos->mutex_stop = 1;
		}
		cpy_philos = cpy_philos->next;
	}
}

void	ps_start_threads(t_philos *philos, t_time_stuff *start_time, int *stop,
			int nb_philos)
{
	t_philos	*cpy_philo;
	int			i;

	cpy_philo = philos;
	i = 0;
	ps_check_mutex_errors(philos);
	if (philos->mutex_stop != 0)
		philos->safety = 0;
	while (cpy_philo != NULL && ++i > 0 && philos->safety < 0 && *stop == 1)
	{
		ps_add_time_structs(philos, cpy_philo, start_time, i);
		if (philos->safety == -1
			&& pthread_create(&cpy_philo->philo, NULL, ps_philosopher_brain,
				(void *)cpy_philo) != 0)
			philos->safety = i;
		cpy_philo = cpy_philo->next;
	}
	ps_overseer_loop(philos, stop, nb_philos);
}
