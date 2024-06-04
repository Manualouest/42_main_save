/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_philosopher_brain.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 23:29:32 by mbirou            #+#    #+#             */
/*   Updated: 2024/05/23 13:28:25 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

int	ps_try_fork(t_philos *philo, t_fork *fork1, t_fork *fork2)
{
	if (pthread_mutex_lock(&philo->mutex->checking_privilege) != 0)
		return (0);
	if (fork1->is_free == 1 && fork2->is_free == 1)
	{
		fork1->is_free = 0;
		fork2->is_free = 0;
		if (pthread_mutex_lock(&fork1->my_fork) != 0)
			return (0);
		ps_write_msg(philo->timestamp, philo, 1);
		if (pthread_mutex_lock(&fork2->my_fork) != 0)
			return (0);
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
	while (pthread_mutex_lock(&philo->stats->status_check) == 0
		&& philo->stats->status != DEAD && *(philo->stats->keep_on)
		&& !got_forks)
	{
		pthread_mutex_unlock(&philo->stats->status_check);
		if (philo->fork && philo->left_fork)
			got_forks = ps_try_fork(philo, philo->fork, philo->left_fork);
		// else if (philo->fork && philo->left_fork)
		// 	got_forks = ps_try_fork(philo, philo->fork, philo->left_fork);
		if (pthread_mutex_lock(&philo->stats->status_check) == 0
			&& *(philo->stats->keep_on)
			&& pthread_mutex_unlock(&philo->stats->status_check) == 0)
			ps_check_for_death(philo);
	}
	if (philo->stats->status != DEAD && *(philo->stats->keep_on)
		&& got_forks)
		philo->stats->status = EATING;
	pthread_mutex_unlock(&philo->stats->status_check);
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

void	ps_unlock_forks(t_philos *philo)
{
	if (philo->stats->status == EATING)
	{
		pthread_mutex_unlock(&philo->fork->my_fork);
		pthread_mutex_unlock(&philo->left_fork->my_fork);
	}
}

void	*ps_philosopher_brain(void *vd_philo)
{
	t_philos	*philo;

	philo = (t_philos *)vd_philo;
	while (pthread_mutex_lock(&philo->stats->status_check) == 0
		&& philo->stats->status != DEAD && *(philo->stats->keep_on))
	{
		pthread_mutex_unlock(&philo->stats->status_check);
		ps_take_forks(philo);
		if (pthread_mutex_lock(&philo->stats->status_check) != 0)
			return (0);
		if (*(philo->stats->keep_on) && philo->stats->status == EATING)
		{
			pthread_mutex_unlock(&philo->stats->status_check);
			if (philo->stats->nb_meals_left > 0)
				philo->stats->nb_meals_left --;
			ps_write_msg(philo->timestamp, philo, 2);
			gettimeofday(&philo->time->timeval, NULL);
			ps_wait_time(philo, philo->stats->eat_time);
			if (pthread_mutex_lock(&philo->stats->status_check) != 0)
				return (0);
		}
		pthread_mutex_unlock(&philo->stats->status_check);
		if (pthread_mutex_lock(&philo->stats->status_check) != 0)
			return (0);
		if (*(philo->stats->keep_on) && philo->stats->status != DEAD)
		{
			ps_make_philo_sleep(philo);
		}
		pthread_mutex_unlock(&philo->stats->status_check);
		if (pthread_mutex_lock(&philo->stats->status_check) != 0)
			return (0);
		if (*(philo->stats->keep_on) && philo->stats->status != DEAD)
		{
			pthread_mutex_unlock(&philo->stats->status_check);
			philo->stats->status = THINKING;
			ps_write_msg(philo->timestamp, philo, 4);
			ps_make_philo_think(philo);
			if (pthread_mutex_lock(&philo->stats->status_check) != 0)
				return (0);
		}
		pthread_mutex_unlock(&philo->stats->status_check);
	}
	pthread_mutex_unlock(&philo->stats->status_check);
	ps_unlock_forks(philo);
	return (0);
}
