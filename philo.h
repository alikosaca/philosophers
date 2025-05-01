#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <stdbool.h>
#include <limits.h>


typedef enum	s_status
{
	DEAD = 0,
	EATTING = 1,
	SLEEPING = 2,
	THINKING = 3,
	FORK_TAKEN = 3,
}				t_status;

typedef struct	s_fork
{
    pthread_mutex_t    mutex;
    int                id;
    int                status;
}				t_fork;

typedef struct	s_philosopher
{
	pthread_t			thread;
	int					id;
	int					eat_count;
	t_fork				*left_fork;
	t_fork				*right_fork;
	long long			last_meal_time;
	bool				is_eating;
	struct s_simulation	*simulation;
}				t_philosopher;

typedef struct	s_simulation
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_meals;
	bool			simulation_end;
	long long		start_time;
	t_philosopher	*philosophers;
	t_fork			*forks;
	pthread_mutex_t	write_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	end_mutex;
}				t_simulation;

#endif