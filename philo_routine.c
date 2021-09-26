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
/*=//	while (1)
//	{
	printf("Soy el filo %d\n",ph.idx);
	if (ph.idx / 2)
		pthread_mutex_lock(&ph.m_fork[1]);
	if (ph.prg->forks[1])
		printf("Filo %d pilla sitio\n", ph.idx);
	ph.prg->forks[1] = 0;
	pthread_mutex_unlock(&ph.m_fork[1]);
//	}*/
//	printf("Tenedores %d vale %d\n", 0, ph.prg->forks[0]);
//	printf("Tenedores %d vale %d\n", 1, ph.prg->forks[1]);
	while (1)
	{
		if (ph.idx % 2)
		{
			pthread_mutex_lock(&ph.prg->m_print);
			printf("Soy el filo %d\n", ph.idx);
			pthread_mutex_unlock(&ph.prg->m_print);
			if (ph.prg->forks[0] && ph.prg->forks[1])
			{
				pthread_mutex_lock(&ph.m_fork[0]);
				ph.prg->forks[0] = 0;
				pthread_mutex_lock(&ph.prg->m_print);
				printf("El filo %d ha pillado el tenedor 1\n", ph.idx);
				pthread_mutex_unlock(&ph.prg->m_print);
				ph.l_fork = 1;
				pthread_mutex_lock(&ph.m_fork[1]);
				ph.prg->forks[1] = 0;
				pthread_mutex_lock(&ph.prg->m_print);
				printf("El filo %d ha pillado el tenedor 2\n", ph.idx);
				pthread_mutex_unlock(&ph.prg->m_print);
				ph.r_fork = 1;
			}
			if (ph.l_fork && ph.r_fork)
			{
				pthread_mutex_lock(&ph.prg->m_print);
				printf("El filo %d is eating\n", ph.idx);
				pthread_mutex_unlock(&ph.prg->m_print);
				ph.prg->forks[0] = 1;
				ph.prg->forks[1] = 1;
				ph.l_fork = 0;
				ph.r_fork = 0;
				ph.has_eaten = 1;
				usleep(ph.prg->eat);
				pthread_mutex_unlock(&ph.m_fork[0]);
				pthread_mutex_unlock(&ph.m_fork[1]);
				pthread_mutex_lock(&ph.prg->m_print);
				printf("El filo %d is sleeping\n", ph.idx);
				usleep(ph.prg->slp);
				pthread_mutex_unlock(&ph.prg->m_print);
			}
		}
		else if (ph.idx / 2)
		{
			pthread_mutex_lock(&ph.prg->m_print);
			printf("Soy el otro %d\n", ph.idx);
			pthread_mutex_unlock(&ph.prg->m_print);
			if (ph.prg->forks[0] && ph.prg->forks[1])
			{
				pthread_mutex_lock(&ph.m_fork[0]);
				ph.prg->forks[0] = 0;
				pthread_mutex_lock(&ph.prg->m_print);
				printf("El filo %d ha pillado el tenedor 1\n", ph.idx);
				pthread_mutex_unlock(&ph.prg->m_print);
				ph.l_fork = 1;
				pthread_mutex_lock(&ph.m_fork[1]);
				ph.prg->forks[1] = 0;
				pthread_mutex_lock(&ph.prg->m_print);
				printf("El filo %d ha pillado el tenedor 2\n", ph.idx);
				pthread_mutex_unlock(&ph.prg->m_print);
				ph.r_fork = 1;
			}
			if (ph.l_fork && ph.r_fork)
			{
				pthread_mutex_lock(&ph.prg->m_print);
				printf("El filo %d is eating\n", ph.idx);
				pthread_mutex_unlock(&ph.prg->m_print);
				ph.prg->forks[0] = 1;
				ph.prg->forks[1] = 1;
				ph.l_fork = 0;
				ph.r_fork = 0;
				ph.has_eaten = 1;
				usleep(ph.prg->eat);
				pthread_mutex_unlock(&ph.m_fork[0]);
				pthread_mutex_unlock(&ph.m_fork[1]);
				pthread_mutex_lock(&ph.prg->m_print);
				printf("El filo %d is sleeping\n", ph.idx);
				usleep(ph.prg->slp);
				pthread_mutex_unlock(&ph.prg->m_print);
			}
		}
		sleep(1);
	}
	return (NULL);
}
