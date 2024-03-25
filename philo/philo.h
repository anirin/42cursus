#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct 	s_setting
{
	int number_of_philosophers;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int eat_times;
}				t_setting;

typedef struct s_philo
{
	int index;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	long start_usec;
	long start_sec;
	long latest_eat_time;
}				t_philo;

typedef struct s_limiter
{
	pthread_mutex_t *limites;
}				t_limiter;

typedef struct s_data //哲学者がしゃべっていないに抵触する可能性あり
{
	t_setting setting;
	t_philo philo;
	t_limiter limiter;
}				t_data;

//init
t_setting	get_setting(char **argv);
pthread_mutex_t	*init_forks(int number_of_philosophers);
t_philo	*init_philos_data(t_setting data, pthread_mutex_t *forks, struct timeval tv);
t_limiter	limiter_init(t_setting setting);
t_data	*integrate_data(t_setting setting, t_philo *philo, t_limiter limiter);

//ckeck
void print_philos(t_data data,t_philo *philo);
void print_data(t_data *data);

//life cycle
pthread_t *create_philos_thread(t_data *data);
void philo_print(t_philo philo, char *str);

//end
void finish_pthreads(int number_of_philosophers, pthread_t *philo);
void finish_mutex(int number_of_philosophers, pthread_mutex_t *forks);

#endif
