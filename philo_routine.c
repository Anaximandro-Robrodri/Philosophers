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
/*	while (1)
	{
		printf("Soy el filo %d\n", ph->idx);
		printf("El filo %d tiene acceso a t_die %d\n", ph->idx, ph->prg->die);
		printf("El filo %d tiene acceso a t_eat %d\n", ph->idx, ph->prg->eat);
		printf("El filo %d tiene acceso a t_slp %d\n", ph->idx, ph->prg->slp);
		printf("El filo %d tiene acceso a n_eat %d\n", ph->idx, ph->prg->n_eat);
		sleep(1);
	}*/
	pthread_mutex_lock(&ph->prg->m_print);
	printf("Philo Nº %d has taken a fork\n", ph->idx);
	pthread_mutex_unlock(&ph->prg->m_print);
	return (NULL);
}
