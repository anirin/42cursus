#include "philo.h"

void philo_get_forks(t_philo philo)
{
	pthread_mutex_lock(philo.left_fork);
	philo_print(philo, "take left fork");
	pthread_mutex_lock(philo.right_fork);
	philo_print(philo, "take right fork");
}

void philo_eat(t_setting setting, t_philo philo)
{
	philo_print(philo, "is eating");
	usleep(setting.time_to_eat * 1000);
}

void philo_put_forks(t_philo philo)
{
	pthread_mutex_unlock(philo.left_fork);
	philo_print(philo, "put left fork");
	pthread_mutex_unlock(philo.right_fork);
	philo_print(philo, "put right fork");
}

void philo_sleep(t_setting setting, t_philo philo)
{
	philo_print(philo, "is sleeping");
	usleep(setting.time_to_sleep * 1000);
}

void philo_think(t_philo philo)
{
	philo_print(philo, "is thinking");
}

void philo_lifecycle(t_data data)
{
	int i;

	i = 0;
	//第５匹数がない場合を考慮していない memo
	while (data.setting.eat_times > i)
	{
		philo_get_forks(data.philo);
		philo_eat(data.setting, data.philo);
		philo_put_forks(data.philo);
		philo_sleep(data.setting, data.philo);
		philo_think(data.philo);
		i++;
	}
}

pthread_t *create_philos_thread(t_data *data)
{
	pthread_t	*philo_thread;
	int i;

	i = 0;
	philo_thread = malloc(data[0].setting.number_of_philosophers * sizeof(pthread_t));
	while (data[0].setting.number_of_philosophers > i)
	{
		printf("philo [%d] is born\n", data[i].philo.index);
		pthread_create(&philo_thread[i], NULL, (void *)philo_lifecycle, &data[i]);
		i++;
	}
	return (philo_thread);
}