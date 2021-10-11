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

void	print_action(t_philo *ph, char *msg, int time)
{
	pthread_mutex_lock(&ph->prg->m_print);
	printf(msg, time, ph->idx);
	pthread_mutex_unlock(&ph->prg->m_print);
}

void	print_dead(t_philo *ph)
{
	pthread_mutex_lock(&ph->prg->m_print);
	printf(DAMOCLES_SWORD, (ph->last_eat + ph->prg->die) - ph->prg->start, ph->idx);
	pthread_mutex_unlock(&ph->prg->m_print);
}