/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalle-a <ldalle-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:43:12 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/09/15 17:45:01 by ldalle-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	ft_time()
{
	struct timeval tv;

    gettimeofday(&tv,NULL);
    return (((long)tv.tv_sec) * 1000) + (tv.tv_usec / 1000);
}

void	*death_watch(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->id == 3)
		printf("\tCapo lo abbiamo trovato!! %d\n", philo->id);
	return (0);
}

void	*routine(void *arg)
{
	t_philo		*philo;
	pthread_t	death;

	philo = (t_philo*)arg;
		//printf("\tCapo lo abbiamo trovato!! %d\n", philo->id);
	pthread_create(&death, NULL, &death_watch, philo);
	
	return (0);
}


void	launch_threads(t_main *main)
{
	int			i;
	pthread_t	main_thread;
	t_philo		*philo;

	i = -1;
	main->start_time  = ft_time();
	while (++i < main->n_philo)
	{	
		philo = &main->philo[i];
		pthread_create(&main_thread, NULL, &routine, (void *)philo);	//manca controllo sul create != 0
		pthread_detach(main_thread);
	}
}

int main (int argc, char **argv)
{
	t_main	main;

	if (argc >= 5 && argc <= 6)
	{
		if (!init(&main, argc, argv))
		{
			printf("Invalid arguments\n");
			return (1);
		}
		launch_threads(&main);
		//launch_monitoring(&main);
		//free_all(&main);
	}
	else
	{
		printf("Invalid number of parameters\n");
		return (1);
	}
	return (0);
}