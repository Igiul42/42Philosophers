/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalle-a <ldalle-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 11:01:07 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/09/20 12:46:56 by ldalle-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static	void	lock_forks(t_philo *philo)
{
	philo->status = TAKE_FORK;
	if (philo->id % 2)
	{
		pthread_mutex_lock(philo->right_fork);
		select_message(philo);
		if (philo->main->nb_philo == 1)
			while (philo->status != DEAD)
				;
		else
		{
			pthread_mutex_lock(philo->left_fork);
			select_message(philo);
		}
	}	
	else
	{
		pthread_mutex_lock(philo->right_fork);
		select_message(philo);
		pthread_mutex_lock(philo->left_fork);
		select_message(philo);
	}
}

int	has_eaten_enough(t_philo *philo)
{
	if (philo->meal_taken == philo->main->nb_meal)
		return (1);
	return (0);
}

static	void	eat(t_philo *philo)
{
	philo->status = EATING;
	philo->start_eat = elapsed_time(philo->main->start_time);
	select_message(philo);
	ft_usleep(philo->main->t_eat);
	philo->meal_taken++;
	if (philo->main->nb_meal > 0 && has_eaten_enough(philo))
	{
		ptread_mutex_lock(philo->main->finished_meal);
		philo->main->nb_finished_meal = philo->main->nb_finished_meal + 1;
		ptread_mutex_unlock(philo->main->finished_meal);
	}
}

void	philo_cycle(t_philo *philo)
{
	lock_forks(philo);
	eat(philo);
	unlock_fork(philo);
	think(philo);
	usleep(100);
}
