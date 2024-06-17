/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsu <atsu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:59:13 by atokamot          #+#    #+#             */
/*   Updated: 2024/06/17 16:09:48 by atsu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define FORK "has taken a fork\n"
# define EAT "is eating\n"
# define SLEEP "is sleeping\n"
# define THINK "is thinking\n"
# define DIE "died\n"

# define DEAD 1
# define ALIVE 0

# define ERROR 1
# define OK 0

typedef struct s_data
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_each_philo_must_eat;
}					t_data;

typedef struct s_fork
{
	pthread_mutex_t	fork_mutex;
	pthread_mutex_t	owner_mutex;
	bool			status;
	int				owner;
}					t_fork;

typedef struct s_common
{
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	full_mutex;
	pthread_mutex_t	dead_mutex;
	bool			alive;
	int				full;
	long			start_time;
}					t_common;

typedef struct s_philo
{
	int				id;
	int				latest_eat_time;

	pthread_t		routine_thread;

	t_fork			*left_fork;
	t_fork			*right_fork;

	t_common		*common;
	t_data			data;
}					t_philo;

//init
int					init_common(t_common *common);
t_data				set_data(char *argv[]);
t_fork				*init_forks(int num_of_philos);
t_philo				*init_philos(t_data data, t_fork *forks,
						t_common *common_value);

//simulation
void				monitor(t_philo *philos);
int					run_simulation(int num_of_philos, t_philo *philos);

//routine
void				get_fork(t_philo *philo);
void				eat(t_philo *philo);
void				change_fork_owner(t_philo *philo);
void				philo_sleep(t_philo *philo);
void				think(t_philo *philo);

//time
long				get_current_time(void);
void				wait_check_point(t_philo *philo);

//print
void				print_philo_status(t_philo *philo, char *status);

//clean_up
void				clean_up_common(t_common *common);
void				clean_up_forks(t_fork *forks, int num_of_philos);
void				clean_up(t_philo *philos, t_fork *forks, t_common *common,
						t_data *data);

//error
int					check_error(int argc, char *argv[]);

//libft
int					ft_atoi(const char *str);

//sleep
void				my_usleep(int time);

#endif