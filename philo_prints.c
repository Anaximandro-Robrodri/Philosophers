/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_prints.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 17:56:35 by robrodri          #+#    #+#             */
/*   Updated: 2021/09/27 17:56:37 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	print_action(t_philo *ph, char *msg)
{
	pthread_mutex_lock(&ph->prg->m_print);
	printf(msg, get_time_start() - ph->prg->start, ph->idx);
	pthread_mutex_unlock(&ph->prg->m_print);
}

void	print_dead(t_philo *ph)
{
	pthread_mutex_lock(&ph->prg->m_print);
	printf(DAMOCLES_SWORD, (ph->last_eat + ph->prg->die) - ph->prg->start, ph->idx);
	pthread_mutex_unlock(&ph->prg->m_print);
}

void	ft_destroy_mutex(pthread_mutex_t *m_f, t_prg *prg)
{
	int	i;

	i = 0;
	while (i < prg->n_philo)
	{
		pthread_mutex_destroy(&m_f[i]);
		i++;
	}
	pthread_mutex_destroy(&prg->m_dead);
	pthread_mutex_destroy(&prg->m_print);
	pthread_mutex_destroy(&prg->m_eat);
	free(prg->forks);
	free(m_f);
}