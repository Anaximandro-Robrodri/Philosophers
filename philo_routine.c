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

static void	action_eat(t_philo *ph)
{
	print_eating(ph);
	usleep(ph->prg->eat * 1000);
//	if (get_time_start() > ph->start + ph->prg->slp)
//		ph->alive = 0;
}

static void	action_slp(t_philo *ph)
{
	print_sleeping(ph);
//	printf("Estamos en %d\n", get_time_start());
//	printf("La suma es %d\n", ph->start + ph->prg->slp);
	usleep(ph->prg->slp * 1000);
//	if (get_time_start() > ph->start + ph->prg->slp)
//		ph->alive = 0;
}

static void	action_tnk(t_philo *ph)
{
	print_thinking(ph);
//	if (get_time_start() > ph->start + ph->prg->die)
//		ph->alive = 0;
}

void	*routine(void *tid)
{
	t_philo	ph;

	ph = *(t_philo*)tid;
//	if (ph.idx / 2)
//		usleep(50);
	while (ph.alive)
	{
		action_eat(&ph);
		action_slp(&ph);
		action_tnk(&ph);
	}
	printf("El philo %d se ha morido\n", ph.idx);
	return (NULL);
}
