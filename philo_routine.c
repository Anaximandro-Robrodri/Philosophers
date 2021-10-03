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
	if (ph->idx / 2)		//PHILO PAR
	{
//		odd_philo(ph);
		if (ph->prg->forks[ph->idx - 1])
		{
			print_fork(ph);
			ph->prg->forks[ph->idx - 1] = 0;
		}
		if (ph->prg->forks[ph->idx - 2])
		{
			print_fork(ph);
			ph->prg->forks[ph->idx - 2] = 0;
		}
	}
/*	else					//PHILO IMPAR
	{
//		even_philo(ph);
	}*/
}

/*static void	action_slp(t_philo *ph)
{
	print_sleeping(ph);
	usleep(ph->prg->slp * 1000);
	if (get_time_start() > ph->time_now + ph->prg->slp)
		ph->alive = 0;
	ph->time_now = get_time_start();
}

static void	action_tnk(t_philo *ph)
{
	print_thinking(ph);
	if (get_time_start() > ph->time_now + ph->prg->die)
		ph->alive = 0;
	ph->time_now = get_time_start();
}*/

void	*routine(void *tid)
{
	t_philo	ph;

	ph = *(t_philo*)tid;
	if (ph.idx / 2)
		usleep(50);
	while (ph.alive)
	{
		action_eat(&ph);
//		action_slp(&ph);
//		action_tnk(&ph);
	}
	printf("(%d)Philo %d se ha morido\n", ph.time_now - ph.start, ph.idx);
	return (NULL);
}
