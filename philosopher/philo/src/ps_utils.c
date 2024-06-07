/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:42:42 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/07 22:22:14 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

int	ps_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		i ++;
	}
	return (i);
}

long int	ps_atoi(const char *num)
{
	long int	i;
	long int	sign;
	long int	res;

	i = -1;
	while (num[++i])
		if (num[i] < '0' || num[i] > '9')
			return (-1);
	i = 0;
	sign = 1;
	if (num[i] == '-')
		sign = sign * -1;
	if (num[i] == '+' || num[i] == '-')
		i++;
	res = 0;
	while (num[i] >= '0' && num[i] <= '9')
	{
		res = num[i] - '0' + res * 10;
		i++;
	}
	return (res * sign);
}

static void	ps_free_inner_philo(t_philos *philo)
{
	t_philos	*prev_philo;

	while (philo != NULL)
	{
		if (philo && philo->stats)
			free(philo->stats);
		if (philo && philo->fork)
			free(philo->fork);
		if (philo && philo->time)
			free(philo->time);
		if (philo && philo->timestamp)
			free(philo->timestamp);
		if (philo && philo->waitstamp)
			free(philo->waitstamp);
		prev_philo = philo;
		if (philo)
			philo = philo->next;
		if (prev_philo)
			free(prev_philo);
	}
}

void	ps_free_everything(t_philos *philos, int *args
	, t_time_stuff *time, t_mutex *mutex_list)
{
	if (!mutex_list || !args || !philos || !time)
	{
		free(philos);
		philos = NULL;
	}
	if (mutex_list && args && time)
	{
		pthread_mutex_destroy(&mutex_list->checking);
		pthread_mutex_destroy(&mutex_list->writing);
	}
	pthread_mutex_destroy(&philos->status);
	if (mutex_list)
		free(mutex_list);
	if (args)
		free(args);
	if (philos != NULL)
		ps_free_inner_philo(philos);
	if (time)
		free(time);
}

int	ps_check_for_death(t_philos *philo)
{
	struct s_time_stuff	timestamp;

	gettimeofday(&timestamp.timeval, NULL);
	if (((((philo->timestamp->timeval.tv_sec - 1 - philo->time->timeval.tv_sec)
					* 1000000) + (1000000 - philo->time->timeval.tv_usec)
				+ philo->timestamp->timeval.tv_usec) / 1000)
		>= philo->stats->death_time)
	{
		// ps_write_msg(philo->timestamp, philo, 0);
		ps_philo_status(philo, DEAD);
		return (0);
	}
	return (1);
}
