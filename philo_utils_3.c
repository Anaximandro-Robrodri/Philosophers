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

void	print_action(t_philo *ph, char *msg, uint64_t time)
{
	if (ph->prg->running)
	{
		pthread_mutex_lock(&ph->prg->m_print);
		printf(msg, time, ph->idx);
		pthread_mutex_unlock(&ph->prg->m_print);
	}
}

void	ft_usleep(uint64_t time)
{
	uint64_t	timer;

	timer = get_time_start();
	while ((get_time_start() - timer) < time)
		;
}
