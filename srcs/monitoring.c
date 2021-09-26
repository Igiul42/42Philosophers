/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalle-a <ldalle-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 13:45:20 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/09/26 16:22:08 by ldalle-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	death_monitor(t_main *main)
{
	while (!main->dead_found)
		usleep(100);
	printf("\033[0;31m\n\t PHILO SHOULDN'T DIE \n\n\033[0m");
}

void	meal_and_death_monitor(t_main *main)
{
	char	*time;

	while (!main->dead_found
		&& main->nb_finished_meal < main->nb_philo)
		usleep(100);
	if (main->nb_finished_meal == main->nb_philo && !main->dead_found)
	{
		time = ft_itoa(elapsed_time(main->start_time));
		printf("%s\t", time);
		printf("\033[32mEach philosopher has eaten %d times.\n\033[0m",
			main->nb_meal);
		free(time);
	}
}
