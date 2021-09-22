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
/*//	while (1)
//	{
	printf("Soy el filo %d\n",ph.idx);
	if (ph.idx / 2)
		pthread_mutex_lock(&ph.m_fork[1]);
	if (ph.prg->forks[1])
		printf("Filo %d pilla sitio\n", ph.idx);
	ph.prg->forks[1] = 0;
	pthread_mutex_unlock(&ph.m_fork[1]);
//	}*/

	while (1)
	{
		if (ph.idx / 2 && !ph.has_eaten)
		{
			if (ph.prg->forks[ph.idx - 1])
			{
				pthread_mutex_lock(&ph.m_fork[ph.idx - 1]);
				ph.prg->forks[ph.idx - 1] = 0;
				pthread_mutex_lock(&ph.prg->m_print);
				printf("Philo %d has taken a fork\n", ph.idx);
				pthread_mutex_unlock(&ph.prg->m_print);
				ph.r_fork = 1;
			}
			if (ph.prg->forks[ph.idx - 2])
			{
				pthread_mutex_lock(&ph.m_fork[ph.idx - 2]);
				ph.prg->forks[ph.idx - 2] = 0;
				pthread_mutex_lock(&ph.prg->m_print);
				printf("Philo %d has taken a fork\n", ph.idx);
				pthread_mutex_unlock(&ph.prg->m_print);
				ph.l_fork = 1;
			}
			if (ph.r_fork && ph.l_fork)
			{
				pthread_mutex_lock(&ph.prg->m_print);
				printf("Philo %d is eating\n", ph.idx);
				pthread_mutex_unlock(&ph.prg->m_print);
				usleep(ph.prg->eat);
				ph.r_fork = 0;
				ph.r_fork = 0;
				pthread_mutex_unlock(&ph.m_fork[ph.idx - 1]);
				pthread_mutex_unlock(&ph.m_fork[ph.idx - 2]);
				ph.has_eaten = 1;
			}
		}
		else if (ph.idx % 2 && !ph.has_eaten)
		{
			if (ph.prg->forks[ph.idx - 1])
			{
				pthread_mutex_lock(&ph.m_fork[ph.idx - 1]);
				ph.prg->forks[ph.idx - 1] = 0;
				pthread_mutex_lock(&ph.prg->m_print);
				printf("Philo %d has taken a fork\n", ph.idx);
				pthread_mutex_unlock(&ph.prg->m_print);
				ph.r_fork = 1;
			}
			if (ph.prg->forks[ph.idx])
			{
				pthread_mutex_lock(&ph.m_fork[ph.idx - 2]);
				ph.prg->forks[ph.idx] = 0;
				pthread_mutex_lock(&ph.prg->m_print);
				printf("Philo %d has taken a fork\n", ph.idx);
				pthread_mutex_unlock(&ph.prg->m_print);
				ph.l_fork = 1;
			}
			if (ph.r_fork && ph.l_fork)
			{
				pthread_mutex_lock(&ph.prg->m_print);
				printf("Philo %d is eating\n", ph.idx);
				pthread_mutex_unlock(&ph.prg->m_print);
				usleep(ph.prg->eat);
				ph.r_fork = 0;
				ph.r_fork = 0;
				pthread_mutex_unlock(&ph.m_fork[ph.idx - 1]);
				pthread_mutex_unlock(&ph.m_fork[ph.idx]);
				ph.has_eaten = 1;
			}
			sleep(1);
		}
	}
	return (NULL);
}
