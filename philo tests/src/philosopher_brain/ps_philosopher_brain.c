/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_philosopher_brain.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 23:29:32 by mbirou            #+#    #+#             */
/*   Updated: 2024/05/19 20:11:54 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

int	ps_try_fork(t_philos *philo, t_fork *fork1, t_fork *fork2)
{
	pthread_mutex_lock(&philo->mutex->checking_privilege);
	if (fork1->is_free == 1 && fork2->is_free == 1)
	{
		fork1->is_free = 0;
		fork2->is_free = 0;
		pthread_mutex_lock(&fork1->my_fork);
		ps_write_msg(philo->timestamp, philo, 1);
		pthread_mutex_lock(&fork2->my_fork);
		ps_write_msg(philo->timestamp, philo, 1);
		pthread_mutex_unlock(&philo->mutex->checking_privilege);
		return (1);
	}
	pthread_mutex_unlock(&philo->mutex->checking_privilege);
	return (0);
}

void	ps_take_forks(t_philos *philo)
{
	int	got_forks;

	got_forks = 0;
	while (philo->stats->status != DEAD && *(philo->stats->keep_on)
		&& !got_forks)
	{
		if (philo->stats->id % 2 == 0 && philo->fork && philo->left_fork)
			got_forks = ps_try_fork(philo, philo->left_fork, philo->fork);
		else if (philo->fork && philo->left_fork)
			got_forks = ps_try_fork(philo, philo->fork, philo->left_fork);
		if (*(philo->stats->keep_on))
			ps_check_for_death(philo);
	}
	if (philo->stats->status != DEAD && *(philo->stats->keep_on)
		&& got_forks)
		philo->stats->status = EATING;
}

void	ps_make_philo_think(t_philos *philo)
{
	gettimeofday(&philo->waitstamp->timeval, NULL);
	gettimeofday(&philo->timestamp->timeval, NULL);
	while (philo->stats->status != DEAD
		&& ((((philo->timestamp->timeval.tv_sec - 1
						- philo->waitstamp->timeval.tv_sec) * 1000000)
				+ (1000000 - philo->waitstamp->timeval.tv_usec)
				+ philo->timestamp->timeval.tv_usec))
		< ((philo->stats->death_time * 1000)
			- (philo->stats->sleep_time * 1000)
			- (philo->stats->eat_time * 1000)) / 10)
	{
		usleep(1);
		gettimeofday(&philo->timestamp->timeval, NULL);
	}
}

void	*ps_philosopher_brain(void *vd_philo)
{
	t_philos	*philo;

	philo = (t_philos *)vd_philo;
	while (philo->stats->status != DEAD && *(philo->stats->keep_on))
	{
		ps_take_forks(philo);
		if (philo->stats->status == EATING && *(philo->stats->keep_on))
		{
			if (philo->stats->nb_meals_left > 0)
				philo->stats->nb_meals_left --;
			ps_write_msg(philo->timestamp, philo, 2);
			gettimeofday(&philo->time->timeval, NULL);
			ps_wait_time(philo, philo->stats->eat_time);
		}
		if (philo->stats->status != DEAD && *(philo->stats->keep_on))
			ps_make_philo_sleep(philo);
		if (philo->stats->status != DEAD && *(philo->stats->keep_on))
		{
			philo->stats->status = THINKING;
			ps_write_msg(philo->timestamp, philo, 4);
			ps_make_philo_think(philo);
		}
	}
	return (0);
}
