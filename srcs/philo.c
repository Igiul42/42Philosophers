/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalle-a <ldalle-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:43:12 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/09/20 11:58:21 by ldalle-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*death_watch(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->main->nb_meal > 0)
	{
		while (is_alive(philo) && is_hungry(philo))
			if (is_dead(philo))
				break ;
	}
	else
	{
		while (is_alive(philo))
			if (is_dead(philo))
				break ;
	}
	return ((void *) 0);
}

void	*routine(void *arg)
{
	t_philo		*philo;
	pthread_t	death;

	philo = (t_philo *)arg;
	if (pthread_create(&death, NULL, &death_watch, philo) != 0)
		printf("Failed create thread"); //sistemare il return
	if (philo->main->nb_meal > 0)
		while (is_alive(philo) && is_hungry(philo))
			philo_cycle(philo);
	else
		while (is_alive(philo))
			philo_cycle(philo);
	return ((void *) 0);
}

void	launch_threads(t_main *main)
{
	int			i;
	pthread_t	main_thread;
	t_philo		*philo;

	i = -1;
	main->start_time = ft_time();
	while (++i < main->nb_philo)
	{	
		philo = &main->philo[i];
		if (pthread_create(&main_thread, NULL, &routine, (void *)philo) != 0)
			printf("Failed create main thread");//sistemare il return
		pthread_detach(main_thread);
		usleep(100);
	}
}

int	main(int argc, char **argv)
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
