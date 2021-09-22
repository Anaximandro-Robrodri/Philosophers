/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:18:17 by robrodri          #+#    #+#             */
/*   Updated: 2021/09/15 17:04:57 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	*routine(void *tid)
{
	t_philo	ph;

	ph = *(t_philo*)tid;
//	while (1)
//	{
	printf("Soy el filo %d\n",ph.idx);
	if (ph.idx / 2)
		pthread_mutex_lock(&ph.m_fork[1]);
	if (ph.prg->forks[1])
		printf("Filo %d pilla sitio\n", ph.idx);
	ph.prg->forks[1] = 0;
	pthread_mutex_unlock(&ph.m_fork[1]);
//	}
	return (NULL);
}
