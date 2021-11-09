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

void	print_action(t_philo *ph, char *msg, u_int64_t time)
{
	pthread_mutex_lock(&ph->prg->m_print);
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
	print_action(ph, DAMOCLES_SWORD,
		(get_time_start() - ph->prg->start));
	ph->prg->running = 0;
	pthread_mutex_unlock(&ph->m_dead);
}
