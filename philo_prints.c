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

void	print_fork(t_philo *ph)
{
	pthread_mutex_lock(&ph->prg->m_print);
	if (ph->prg->running == 1)
		printf(FORK_TAKEN, get_time_start() - ph->prg->start, ph->idx);
	pthread_mutex_unlock(&ph->prg->m_print);
}

void	print_eating(t_philo *ph)
{
	pthread_mutex_lock(&ph->prg->m_print);
	if (ph->prg->running == 1)
		printf(EATING, get_time_start() - ph->prg->start, ph->idx);
	pthread_mutex_unlock(&ph->prg->m_print);
}

void	print_sleeping(t_philo *ph)
{
	pthread_mutex_lock(&ph->prg->m_print);
	if (ph->prg->running == 1)
		printf(SLEEPING, get_time_start() - ph->prg->start, ph->idx);
	pthread_mutex_unlock(&ph->prg->m_print);
}

void	print_thinking(t_philo *ph)
{
	pthread_mutex_lock(&ph->prg->m_print);
	if (ph->prg->running == 1)
		printf(THINKING, get_time_start() - ph->prg->start, ph->idx);
	pthread_mutex_unlock(&ph->prg->m_print);
}

void	print_dead(t_philo *ph)
{
	pthread_mutex_lock(&ph->prg->m_print);
	printf(DAMOCLES_SWORD, (ph->last_eat + ph->prg->die) - ph->prg->start, ph->idx);
	pthread_mutex_unlock(&ph->prg->m_print);
}
