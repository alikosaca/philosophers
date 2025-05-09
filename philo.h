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
    pthread_mutex_t	mutex;
    int				id;
    bool			status;
}					t_fork;

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
	int				num_philo;				//Filozof sayısı
	int				time_to_die;			//Bir filozofun son yediği yemekten itibaren bu süre içinde yemek yememesi durumunda öleceği süre
	int				time_to_eat;			//Bir filozofun yemek yediği süre
	int				time_to_sleep;			//Bir filozofun uyuduğu süre
	int				number_of_meals;		//Her filozofun en az bu kadar kez yemek yemesi gerekir "isteğe bağlı".
	bool			simulation_end;
	long long		start_time;
	t_philosopher	*philosophers;
	t_fork			*forks;
	pthread_mutex_t	write_mutex;			/*ekrana yazma işlemi gerçekleşirken bir ekrana yazan işlemin bitmesini bekiyoruz.
												yani diyelim ki A filozofunun uyuduğunu ekrana yazacağız. onu lock yaparıyrouz. aynı anda birden fazla filozof yapmış olduğu durumu ekrnaa yazmasını engelemek/karışıklık olmasını engellemek için kullanıyoruz*/
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	end_mutex;
}				t_simulation;


//Fonksiyon isimleri

//init_sim
int	init_sim(int argc, char **argv, t_simulation *simulation);

//validate
int	validate_argument(int argc, char **argv, t_simulation *simulation);


//utils
int	ft_atoi(char *str);

//Error
int	return_err(char *message);
int	free_and_error(char *str, t_simulation *simulation);



//init_sim
int	init_sim(int argc, char **argv, t_simulation *simulation);

//simulastion
int	simulastion_action(t_simulation *simulastion);


#endif