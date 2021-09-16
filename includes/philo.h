#ifndef PHILO_H
#define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <time.h>
# include <sys/time.h>

typedef enum e_status
{
	THINKING,
	DEAD,
	TAKE_FORK,
	EATING,
	SLEEPING
}				t_status;

typedef struct s_philo
{
	int				id;
	int				status;
	int				meal_taken;
	long			start_eat;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_main	*main;
}				t_philo;

typedef struct s_main
{
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_meal;
	int				nb_finished_meal;
	int				dead_found;
	long			start_time;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	printer;
	pthread_mutex_t	finished_meal;
	pthread_mutex_t	death;
	int				end;
}				t_main;

int		ft_isnumb(char *num);		/* 					*/
int		ft_atoi(const char *nptr);	/*		utils.c		*/
long	ft_time();					/*					*/
int		init(t_main *main, int argc, char **argv); /* init.c */

#endif