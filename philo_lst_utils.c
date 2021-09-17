/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lst_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:18:12 by robrodri          #+#    #+#             */
/*   Updated: 2021/09/11 16:18:13 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_philos(t_philo *ph, t_prg *prg, int i)
{
		ph->prg = prg;
		ph->idx = i + 1;
		ph->l_fork = 1;
		ph->r_fork = 1;
}

void	create_table(t_prg *prg)
{
	t_philo	*ph;
	int		i;

	ph = malloc(sizeof(t_philo*) * prg->n_philo);
	if (!ph)
		return ;
	i = 0;
	while (i < prg->n_philo)
	{
		init_philos(&ph[i], prg, i);
		pthread_mutex_init(&ph[i].ml_fork, NULL);
		pthread_create(&ph[i].t_ph, NULL, routine, &ph[i]);
		i++;
	}

}
