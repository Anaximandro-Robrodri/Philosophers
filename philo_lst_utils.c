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

void	create_table(t_prg *prg)
{
	int	i;

	i = 0;
	prg->philo = malloc(sizeof(t_philo*) * prg->n_philo);
	if (!prg->philo)
		return ;
	while (i < prg->n_philo)
	{
		prg->philo[i].idx = i;
		pthread_create(&prg->philo[i].t_ph, NULL, routine, (void *)prg);
		usleep(50);
		i++;
	}
}
