#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef enum
{
	FORK,
	THINKING,
	EATING,
	SLEEPING,
	DEAD
}				e_status;

typedef struct 	s_setting
{
	int number;
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
}				t_philo;

typedef struct s_time
{
	long start;
	long *current;
}				t_time;
typedef struct s_data //哲学者がしゃべっていないに抵触する可能性あり
{
	t_setting setting;
	t_philo philo;
	t_time time;
}				t_data;

//init
t_setting	get_setting(char **argv);
pthread_mutex_t	*init_forks(int number_of_philosophers);
t_philo	*init_philos(t_setting data, pthread_mutex_t *forks);
t_data	*integrate_data(t_setting setting, t_philo *philo, t_time *time);
t_time *init_time(int number);

//ckeck
void print_philos(t_data data,t_philo *philo);

//print
void print_state(t_data data, e_status status);
void print_data(const t_data *data);

//life cycle
pthread_t *create_philos_thread(t_data *data);
void my_usleep(t_time time, int u_time);

//end
void finish_pthreads(int number_of_philosophers, pthread_t *philo);
void finish_mutex(int number_of_philosophers, pthread_mutex_t *forks);

#endif
