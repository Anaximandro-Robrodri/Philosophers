/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_more_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 10:51:05 by robrodri          #+#    #+#             */
/*   Updated: 2021/10/02 10:51:06 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

int	ft_dead_checker(t_philo *ph, int n)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < n)
		{
			if (!ph[i].alive)
				return (-1);
			i++;
		}
	}
}

void	ft_join_threads(t_philo *ph, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_join(ph[i].t_ph, NULL);
		i++;
	}
}

int	get_time_start(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
