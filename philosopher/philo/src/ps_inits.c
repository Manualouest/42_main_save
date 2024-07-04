/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_inits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 17:19:58 by mbirou            #+#    #+#             */
/*   Updated: 2024/07/01 11:50:50 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

int	*ps_setup_inputs(int argc, char **argv)
{
	int	*inputs;

	inputs = malloc(sizeof(int) * 5);
	if (!inputs)
		return (NULL);
	inputs[0] = ps_atoi(argv[1]);
	inputs[1] = ps_atoi(argv[2]);
	inputs[2] = ps_atoi(argv[3]);
	inputs[3] = ps_atoi(argv[4]);
	if (argc == 6)
		inputs[4] = ps_atoi(argv[5]);
	else
		inputs[4] = -1;
	return (inputs);
}

t_mutex	*ps_setup_mutexs(void)
{
	t_mutex	*mutexs;

	mutexs = malloc(sizeof(*mutexs));
	if (!mutexs)
		return (NULL);
	mutexs->wl_safety = pthread_mutex_init(
			&mutexs->writing_lock, NULL);
	return (mutexs);
}

void	ps_setup_philo(t_philos *philo, int num, int *inputs, t_mutex *mutexs)
{
	if (!philo)
		return ;
	philo->id = num + 1;
	philo->die = inputs[1];
	philo->eat = inputs[2];
	philo->sleep = inputs[3];
	philo->nb_meals = inputs[4];
	philo->status = 1;
	philo->my_fork = malloc(sizeof(*philo->my_fork));
	if (philo->my_fork)
	{
		philo->my_fork->is_free = 1;
		philo->my_fork->f_safety = pthread_mutex_init(
				&philo->my_fork->fork, NULL);
	}
	philo->left_fork = NULL;
	philo->sc_safety = pthread_mutex_init(
			&philo->status_check, NULL);
	philo->shared_mutex = mutexs;
}

t_philos	*ps_setup_philos(int *inputs, t_mutex *mutexs)
{
	t_philos	*philos;
	t_philos	*start;
	t_philos	*prev;
	int			i;

	philos = malloc(sizeof(*philos));
	start = philos;
	i = -1;
	while (++i < inputs[0])
	{
		ps_setup_philo(philos, i, inputs, mutexs);
		if (!philos || !philos->my_fork)
			ps_free(NULL, NULL, philos);
		if (i > 0)
			philos->left_fork = prev->my_fork;
		if (i + 1 < inputs[0])
			philos->next = malloc(sizeof(*philos->next));
		else
			philos->next = NULL;
		prev = philos;
		philos = philos->next;
	}
	if (inputs[0] > 1)
		start->left_fork = prev->my_fork;
	return (start);
}
