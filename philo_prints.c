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
	printf("(%d)Philo %d has taken a fork!\n", get_time_start() - ph->start, ph->idx);
	pthread_mutex_unlock(&ph->prg->m_print);
}

void	print_eating(t_philo *ph)
{
	pthread_mutex_lock(&ph->prg->m_print);
	printf("(%d)Philo %d is eating\n", get_time_start() - ph->start, ph->idx);
	pthread_mutex_unlock(&ph->prg->m_print);
}

void	print_sleeping(t_philo *ph)
{
	pthread_mutex_lock(&ph->prg->m_print);
	printf("(%d)Philo %d is sleeping\n", get_time_start() - ph->start, ph->idx);
	pthread_mutex_unlock(&ph->prg->m_print);
}

void	print_thinking(t_philo *ph)
{
	pthread_mutex_lock(&ph->prg->m_print);
	printf("(%d)Philo %d is thinking\n", get_time_start() - ph->start, ph->idx);
	pthread_mutex_unlock(&ph->prg->m_print);
}

