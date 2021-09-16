/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalle-a <ldalle-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 11:24:38 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/09/16 11:25:39 by ldalle-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int		is_alive(t_philo *philo)
{
	if (philo->status != DEAD && !philo->main->dead_found)
		return (1);
	return (0);
}

int		is_hungry(t_philo *philo)
{
	long	now;

	if (philo->meal_taken < philo->main->nb_meal)
		return (1);
	return (0);
}