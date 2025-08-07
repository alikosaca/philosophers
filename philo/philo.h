#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <stdbool.h>
# include <limits.h>
# include <string.h>

typedef enum	s_status
{
	ATE,
	HUNGRY,
	DEAD,
	SLEEPING,
	THINKING
}				t_status;

typedef struct	s_fork
{
	int				id;
	bool			status;
	pthread_mutex_t	mutex;
}					t_fork;

typedef struct	s_philosopher
{
	int					id;
	int					eat_count;
	pthread_t			thread;
	t_fork				*right_fork;
	t_fork				*left_fork;
	long long			last_meal_time;
	struct s_simulation	*simulation;
}				t_philosopher;

typedef struct	s_simulation
{
	int				num_philo;				//Filozof sayısı
	int				time_to_die;			//Bir filozofun son yediği yemekten itibaren bu süre içinde yemek yememesi durumunda öleceği süre
	int				time_to_eat;			//Bir filozofun yemek yediği süre
	int				time_to_sleep;			//Bir filozofun uyuduğu süre
	int				number_of_meals;		//Her filozofun en az bu kadar kez yemek yemesi gerekir "isteğe bağlı".
	bool			is_dead;
	long long		start_time;

	pthread_mutex_t	*write_mutex;			/*ekrana yazma işlemi gerçekleşirken bir ekrana yazan işlemin bitmesini bekiyoruz. yani diyelim ki A filozofunun uyuduğunu ekrana yazacağız. onu lock yaparıyrouz. aynı anda birden fazla filozof yapmış olduğu durumu ekrana yazmasını engelemek/karışıklık olmasını engellemek için kullanıyoruz*/
	pthread_mutex_t	*dead_lock;
	t_philosopher	*philo;
	t_fork			*forks;
}				t_simulation;


//Fonksiyon isimleri

//init_sim
int	init_sim(int argc, char **argv, t_simulation *sim);

//validate
int	validate_argument(int argc, char **argv);


//utils
int	ft_atoi(char *str);
int	get_current_time(void);
void	ft_usleep(long long time_in_ms, t_simulation *sim);
void take_forks(t_philosopher *p);


//Error
int		return_err(const char *message);
int		cleanup(t_simulation *sim);
void	destroy_mutex(t_simulation *sim);


//handle
void	print_message(char *str, t_philosopher *philo);
void	print_fork_taken(t_simulation *sim);


//run_simulation
int		run_simulation(t_simulation *sim);
void	*philo_routine(void *arg);
void	*monitor_routine(void *arg);


//routine
void	think(t_philosopher *philo);
void	dream(t_philosopher *philo);
void	eat(t_philosopher *philo);

int	check_simulation_end(t_simulation *sim);

#endif
