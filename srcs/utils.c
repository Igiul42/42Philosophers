/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalle-a <ldalle-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:43:16 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/09/20 12:05:51 by ldalle-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	void	free_message_data(char *id, char *time)
{
	free(id);
	free(time);
}

void	print_message(t_philo *philo, char *status, int i, int j)
{
	char	message[100];
	char	*id;
	char	*time;

	pthread_mutex_lock(&philo->main->printer);
	id = ft_itoa(philo->id);
	time = ft_itoa(elapsed_time(philo->start_eat));
	while (time[j])
		message[i++] = time[j++];
	message[i++] = '\t';
	j = 0;
	while (id[j])
		message[i++] = id[j++];
	message[i++] = ' ';
	j = 0;
	while (status[j])
		message[i++] = status[j++];
	message[i] = '\0';
	if ((philo->main->nb_meal > 0
			&& philo->main->nb_philo != philo->main->nb_finished_meal
			&& (philo->status != DEAD && philo->main->end != 1))
		|| !philo->main->dead_found)
		write(1, message, i);
	pthread_mutex_unlock(&philo->main->printer);
	free_message_data(id, time);//da implementare
}

void	select_message(t_philo	*philo)
{
	if ((philo->main->nb_meal > 0
			&& philo->main->nb_philo != philo->main->nb_finished_meal
			&& !philo->main->dead_found)
		|| (!philo->main->dead_found && philo->main->nb_meal == 0))
	{
		if (philo->status == THINKING)
			print_message(philo, "is thinking\n", 0, 0);
		else if (philo->status == TAKE_FORK)
			print_message(philo, "is taken a fork\n", 0, 0);
		else if (philo->status == EATING)
			print_message(philo, "is eating\n", 0, 0);
		else if (philo->status == SLEEPING)
			print_message(philo, "is sleeping\n", 0, 0);
		else if (philo->status == DEAD)
			print_message(philo, "died\n", 0, 0);
	}
}

long	elapsed_time(long starter)
{
	struct timeval	tv;
	long			end;

	gettimeofday(&tv, NULL);
	end = ((tv.tv_sec * 1000) + tv.tv_usec / 1000);
	return (end - starter);
}

long	ft_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((((long)tv.tv_sec) * 1000) + (tv.tv_usec / 1000));
}
