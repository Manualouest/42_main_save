/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_overseer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 18:43:52 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/07 22:33:58 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

int	ps_is_alive(t_philos *philos)
{
	if (pthread_mutex_lock(&philos->status) != 0)
		return (0);
	if (philos->stats->status == DEAD)
	{
		pthread_mutex_unlock(&philos->status);
		return (0);
	}
	pthread_mutex_unlock(&philos->status);
	return (1);
}

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
	(void)stop;
	while (1)
	{
		while (cpy_philos && cpy_philos->stats && ps_is_alive(cpy_philos) && ps_check_for_death(cpy_philos) && philos->safety < 0)
		{
			if (ps_meal_check(cpy_philos, 0) == 0)
				can_stop ++;
			else
				can_stop = 0;
			if (can_stop == nb_philos + 1)
				break ;
			cpy_philos = cpy_philos->next;
		}
		if (cpy_philos && !ps_is_alive(cpy_philos))
			break ;
		cpy_philos = philos;
		usleep(256);
	}
	ps_write_msg(cpy_philos->timestamp, cpy_philos, 0, 1);
	cpy_philos = philos;
	while (cpy_philos)
	{
		ps_philo_status(cpy_philos, DEAD);
		cpy_philos = cpy_philos->next;
	}
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
		if (cpy_philos->mutex && (cpy_philos->mutex->c_safety != 0
			|| cpy_philos->mutex->w_safety != 0
			|| cpy_philos->s_safety != 0))
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
