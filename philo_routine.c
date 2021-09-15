/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:18:17 by robrodri          #+#    #+#             */
/*   Updated: 2021/09/11 16:18:19 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	*routine(void *tid)
{
	t_prg	*p;

	p = (t_prg*)tid;
	while (1)
	{
		printf("N philos %d\n", p->n_philo);
		printf("Time to die %d\n", p->die);
		printf("Time to sleep %d\n", p->slp);
		printf("Time to eat %d\n", p->eat);
		printf("N eat %d\n", p->n_eat);
		sleep(1);
	}
	return (NULL);
}
