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

#include "philo.h"

static void	action_slp(t_philo *ph)
{
	print_action(ph, SLEEPING);
	ft_usleep(ph->prg->slp);
}

void	*routine(void *tid)
{
	t_philo	*ph;

	ph = (t_philo *)tid;
	if (ph->prg->n_philo == 1)
	{
		print_action(ph, FORK_TAKEN);
		ft_usleep(ph->prg->die);
		return (NULL);
	}
	if (ph->idx % 2)
		ft_usleep(100);
	while (ph->prg->running)
	{
		action_eat(ph);
		action_slp(ph);
		print_action(ph, THINKING);
	}
	return (NULL);
}
