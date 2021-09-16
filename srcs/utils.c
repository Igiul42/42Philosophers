/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldalle-a <ldalle-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 16:43:16 by ldalle-a          #+#    #+#             */
/*   Updated: 2021/09/16 10:41:45 by ldalle-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	ft_time()
{
	struct timeval tv;

    gettimeofday(&tv,NULL);
    return (((long)tv.tv_sec) * 1000) + (tv.tv_usec / 1000);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	res;
	int	i;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\v'
		|| nptr[i] == '\n' || nptr[i] == '\f'
		|| nptr[i] == '\r')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -sign;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

int	ft_isnumb(char *num)
{
	int	i;

	i = 0;
	if (num[i] != '\0')
	{
		while (num[i])
		{
			if (num[i] == '+' || num[i] == '-')
				i++;
			else
				break ;
		}
		while (num[i])
		{
			if (num[i] >= '0' && num[i] <= '9')
				i++;
			else
				return (0);
		}
		return (1);
	}
	return (0);
}