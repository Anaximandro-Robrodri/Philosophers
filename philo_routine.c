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
	t_philo	*ph;

	ph = tid;
	while (1)
	{
		pthread_mutex_lock(&ph->m_fork[ph->idx - 1]);
		pthread_mutex_lock(&ph->prg->m_print);
		printf("Philo %d has taken a fork\n", ph->idx);
		pthread_mutex_unlock(&ph->prg->m_print);
		pthread_mutex_lock(&ph->m_fork[ph->idx - 1]);
		sleep(1);
	}
	return (NULL);
}
