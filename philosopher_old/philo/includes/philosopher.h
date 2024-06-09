/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birou@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 23:30:52 by mbirou            #+#    #+#             */
/*   Updated: 2024/06/07 22:23:49 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef enum e_states
{
	EATING,
	SLEEPING,
	THINKING,
	DEAD
}	t_states;

typedef struct s_time_stuff
{
	struct timeval	timeval;
}						t_time_stuff;

typedef struct s_fork
{
	int				is_free;
}					t_fork;

typedef struct s_stats
{
	int				id;
	t_states		status;
	int				nb_meals_left;
	int				eat_time;
	int				sleep_time;
	int				death_time;
	int				*keep_on;
	long int		start_time;
}					t_stats;

typedef struct s_mutex
{
	pthread_mutex_t	checking;
	int				c_safety;
	pthread_mutex_t	writing;
	int				w_safety;
}					t_mutex;

typedef struct s_philos
{
	pthread_t			philo;
	int					safety;
	int					mutex_stop;
	struct s_stats		*stats;
	struct s_philos		*next;
	struct s_fork		*fork;
	struct s_fork		*left_fork;
	struct s_time_stuff	*time;
	struct s_time_stuff	*timestamp;
	struct s_time_stuff	*waitstamp;
	struct s_mutex		*mutex;
	pthread_mutex_t		status;
	int					s_safety;
}					t_philos;

// ps_utils.c
int			ps_strlen(const char *s);
long int	ps_atoi(const char *nptr);
void		ps_free_everything(t_philos *philos, int *args,
				t_time_stuff *time, t_mutex *mutex_list);
int			ps_check_for_death(t_philos *philo);

// ps_parsing.c
int			ps_input_parsing(int nb_params, char **params);

// ps_innits.c
void		ps_innit_philos(t_philos *philos, int *args, int *stop);
void		ps_insert_mutex(t_philos *philos, t_mutex *mutex_list);
void		ps_add_time_structs(t_philos *origine, t_philos *philo,
				t_time_stuff *start_time, int i);

// ps_philosopher_brain.c
void		*ps_philosopher_brain(void *vd_philo);
int			ps_philo_status(t_philos *philo, int new);

// ps_brain_utils.c
void		ps_write_msg(t_time_stuff *timestamp, t_philos *philo, int msg_id,
				int backdoor);
void		ps_wait_time(t_philos *philo, int wait, int reason);
void		ps_make_philo_sleep(t_philos *philo);
int			ps_meal_check(t_philos *philo, int ate);

// ps_itoa.c
char		*ps_itoa(long int n);

// ps_overseer.c
int			ps_is_alive(t_philos *philos);
void		ps_overseer_loop(t_philos *philos, int *stop, int nb_philos);
void		ps_start_threads(t_philos *philos, t_time_stuff *start_time,
				int *stop, int nb_philos);

#endif