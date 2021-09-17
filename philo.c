/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robrodri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:17:54 by robrodri          #+#    #+#             */
/*   Updated: 2021/09/11 16:17:56 by robrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*static void	print_instructions(void)
{
	printf("Insert arguments like this: \n");
	printf("[Number of philoshopers] , [Time to die], [Time to eat] \n");
	printf("[Time to sleep] , (OPTIONAL) [Number of times each philosopher must eat] \n");
}*/

void	ft_error(void)
{
	printf("An error has ocurred\n");
	exit (-1);
}

static void	store_args(int argc, char **argv, t_prg *prg)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (i == 1)
		{
			prg->n_philo = ft_atoi(argv[i]);
			if (prg->n_philo > MAX_PHILO || prg->n_philo < 2)
				ft_error ();
		}
		else if (i == 2)
			prg->die = ft_atoi(argv[i]);
		else if (i == 3)
			prg->eat = ft_atoi(argv[i]);
		else if (i == 4)
			prg->slp = ft_atoi(argv[i]);
		else if (i == 5)
			prg->n_eat = ft_atoi(argv[i]);
		i++;
	}
	if (i == 5)
		prg->n_eat = -1;
}

static int	check_args(int argc, char **argv)
{
	while (--argc)
	{
		if (!ft_error_control(argc, argv))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_prg	prg;

	if (argc == 5 || argc == 6)
	{
		if (check_args(argc, argv))
		{
			printf("Diogenes Rules\n");
			store_args(argc, argv, &prg);
			create_table(&prg);
		}
		else
			ft_error ();
	}
//	print_instructions();
	pthread_exit(NULL);
	return (0);
}
