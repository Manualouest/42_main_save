/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_brain_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 23:48:37 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/04 20:29:44 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosopher.h>

void	ps_find_msg(int msg_id)
{
	if (msg_id == 0)
		write(1, " died\n", 6);
	if (msg_id == 1)
		write(1, " has taken a fork\n", 18);
	if (msg_id == 2)
		write(1, " is eating\n", 11);
	if (msg_id == 3)
		write(1, " is sleeping\n", 13);
	if (msg_id == 4)
		write(1, " is thinking\n", 13);
}

void	ps_write_msg(t_time_stuff *timestamp, t_philos *philo, int msg_id)
{
	char	*text;

	if (pthread_mutex_lock(&philo->mutex->writing_privilege) != 0)
		return ;
	if (*(philo->stats->keep_on) == 0)
	{
		pthread_mutex_unlock(&philo->mutex->writing_privilege);
		return ;
	}
	gettimeofday(&timestamp->timeval, NULL);
	text = ps_itoa(((timestamp->timeval.tv_sec * 1000)
				+ (timestamp->timeval.tv_usec / 1000))
			- philo->stats->start_time);
	write(1, text, ps_strlen(text));
	free(text);
	write(1, " ", 1);
	text = ps_itoa(philo->stats->id);
	write(1, text, ps_strlen(text));
	ps_find_msg(msg_id);
	free(text);
	pthread_mutex_unlock(&philo->mutex->writing_privilege);
}

void	ps_wait_time(t_philos *philo, int wait)
{
	gettimeofday(&philo->waitstamp->timeval, NULL);
	gettimeofday(&philo->timestamp->timeval, NULL);
	while (philo->stats->status != DEAD
		&& ((((philo->timestamp->timeval.tv_sec - 1
						- philo->waitstamp->timeval.tv_sec) * 1000000)
				+ (1000000 - philo->waitstamp->timeval.tv_usec)
				+ philo->timestamp->timeval.tv_usec) / 1000)
		< wait)
	{
		ps_check_for_death(philo);
		usleep(1);
		gettimeofday(&philo->timestamp->timeval, NULL);
	}
}

void	ps_make_philo_sleep(t_philos *philo)
{
	pthread_mutex_unlock(&philo->stats->status_check);
	ps_write_msg(philo->timestamp, philo, 3);
	pthread_mutex_unlock(&philo->fork->my_fork);
	pthread_mutex_unlock(&philo->left_fork->my_fork);
	if (pthread_mutex_lock(&philo->mutex->checking_privilege) != 0)
		return ;
	philo->fork->is_free = 1;
	philo->left_fork->is_free = 1;
	pthread_mutex_unlock(&philo->mutex->checking_privilege);
	philo->stats->status = SLEEPING;
	ps_wait_time(philo, philo->stats->sleep_time);
	if (pthread_mutex_lock(&philo->stats->status_check) != 0)
		return ;
}

void	ps_check_for_death(t_philos *philo)
{
	gettimeofday(&philo->timestamp->timeval, NULL);
	if (((((philo->timestamp->timeval.tv_sec - 1 - philo->time->timeval.tv_sec)
					* 1000000) + (1000000 - philo->time->timeval.tv_usec)
				+ philo->timestamp->timeval.tv_usec) / 1000)
		>= philo->stats->death_time)
	{
		ps_write_msg(philo->timestamp, philo, 0);
		if (pthread_mutex_lock(&philo->stats->status_check) != 0)
			return ;
		ps_unlock_forks(philo);
		philo->stats->status = DEAD;
		pthread_mutex_unlock(&philo->stats->status_check);
	}
}
