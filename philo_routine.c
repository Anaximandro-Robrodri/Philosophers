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
	if (ph->alive && ph->prg->running)
	{
		if (ph->idx == 1)
			philo_eat(ph, ph->prg->n_philo - 1, 0);
		else if (ph->idx % 2)
			philo_eat(ph, ph->idx - 2, ph->idx - 1);
		else
			philo_eat(ph, ph->idx - 1, ph->idx - 2);
	}
}

static void	action_slp(t_philo *ph)
{
	if (ph->alive && ph->has_eaten && ph->prg->running)
	{
		print_action(ph, SLEEPING, get_time_start() - ph->prg->start);
		ft_usleep(ph->prg->slp);
		ph->has_eaten = 0;
		ph->thk = 0;
	}
}

static void	action_tnk(t_philo *ph)
{
	if (ph->alive && !ph->thk && ph->prg->running)
	{
		print_action(ph, THINKING, get_time_start() - ph->prg->start);
		ph->thk = 1;
	}
}

void	*routine(void *tid)
{
	t_philo	*ph;

	ph = (t_philo*)tid;
	if (ph->idx % 2)
		usleep(50);
	while (ph->alive && ph->prg->running)
	{
		action_eat(ph);
		action_slp(ph);
		action_tnk(ph);
	}
	return (NULL);
}
