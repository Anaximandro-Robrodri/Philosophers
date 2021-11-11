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

#include "philo.h"

void	print_action(t_philo *ph, char *msg)
{
	u_int64_t	time;

	if (!ph->prg->running)
		return ;
	pthread_mutex_lock(&ph->prg->m_print);
	time = get_time_start() - ph->prg->start;
	if (ph->prg->running)
		printf(msg, time, ph->idx);
	pthread_mutex_unlock(&ph->prg->m_print);
}

void	ft_usleep(u_int64_t time)
{
	u_int64_t	timer;

	timer = get_time_start();
	while ((get_time_start() - timer) < time)
		usleep(100);
}

void	end_program(t_philo *ph)
{
	pthread_mutex_lock(&ph->m_dead);
	print_action(ph, DAMOCLES_SWORD);
	ph->prg->running = 0;
	pthread_mutex_unlock(&ph->m_dead);
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
