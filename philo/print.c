#include "philo.h"

void	print_state(t_data data, e_status status)
{
	long diff;
	char content[5][20] = {
		"has taken a fork",
		"is thinking",
		"is eating",
		"is sleeping",
		"is dead"
		};

	diff = 	*data.time.current - data.time.start;
	printf("%ld %d %s\n", diff, data.philo.index, content[status]);
}

void	print_state_now(t_data data, e_status status)
{
	long diff;
	char content[5][20] = {
		"has taken a fork",
		"is thinking",
		"is eating",
		"is sleeping",
		"is dead"
		};

	diff = 	get_current_time() - data.time.start;
	printf("%ldms    %d %s\n", diff, data.philo.index, content[status]);
}

void print_data(t_data data)
{
    printf("Settings:\n");
    printf(" Number of Philosophers: %d\n", data.setting.number);
    printf(" Time to Die: %d ms\n", data.setting.time_to_die);
    printf(" Time to Eat: %d ms\n", data.setting.time_to_eat);
    printf(" Time to Sleep: %d ms\n", data.setting.time_to_sleep);
    printf(" Number of Times Each Philosopher Must Eat: %d\n", data.setting.eat_times);
    
    printf("Philosopher:\n");
    printf(" Index: %d\n", data.philo.index);
    printf(" Left Fork: %p\n", (void *)data.philo.left_fork);
    printf(" Right Fork: %p\n", (void *)data.philo.right_fork);
    
    printf("Time:\n");
    printf(" Start: %ld ms\n", data.time.start);
    printf(" Current: %ld ms\n", *(data.time.current));
	printf("--------------------------\n");
}