#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>

#define Dirty false
#define Clean true
#define Request true
#define Fork "has taken a fork\n"
#define Eat "is eating\n"
#define Sleep "is sleeping\n"
#define Think "is thinking\n"
#define Die "died\n"

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
	pthread_mutex_t	mutex;
	bool			status;
	int				owner;
}					t_fork;

typedef struct s_common
{
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*full_mutex;
	bool			*alive;
	int				*full;
}					t_common;

typedef struct s_philo
{
	pthread_t		routine_thread;
	pthread_t		monitor_thread;

	t_fork			*left_fork;
	t_fork			*right_fork;

	int				id;

	int				latest_eat_time;
	long			start_time;

	bool			*alive;
	int				*full;

	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*full_mutex;

	t_data			data;
}					t_philo;

//init
t_common			init_common(void);
t_data				set_data(char *argv[]);
t_fork				*init_forks(int num_of_philos);
t_philo				*init_philos(t_data data, t_fork *forks, long start_time,
						t_common common_value);

//simulation
void				run_simulation(int num_of_philos, t_philo *philos);

//routine
void				get_fork(t_philo *philo);
void				eat(t_philo *philo);
void				clean_fork(t_philo *philo);
void				philo_sleep(t_philo *philo);
void				think(t_philo *philo);

//time
long				get_current_time(void);
void				wait_check_point(t_philo *philo);

//print
void				print_philo_status(t_philo *philo, char *status);

//clean_up
void				clean_up(t_philo *philos, t_fork *forks, t_common common);

//error
int					check_error(int argc, char *argv[]);