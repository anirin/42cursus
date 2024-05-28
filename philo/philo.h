#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

#define Dirty false
#define Clean true
#define Request true
#define Fork "has taken a fork\n"
#define Eat "is eating\n"
#define Sleep "is sleeping\n"
#define Think "is thinking\n"
#define Die "died\n"


typedef struct s_fork
{
	pthread_mutex_t	mutex;
	bool			status;
	bool			requested;
}					t_fork;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	t_fork			*left_fork;
	t_fork			*right_fork;
	int				check_point;
	long			start_time;

	t_data			data;
}					t_philo;

typedef struct s_data
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_times_each_philo_must_eat;
}					t_data;

//init
t_data				set_data(char *argv[]);
t_fork				*init_forks(int num_of_philos);
t_philo				*init_philos(t_data data, t_fork *forks, long start_time);

//simulation
void				run_simulation(t_data data, t_philo *philos);

//routine
