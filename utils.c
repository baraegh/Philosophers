/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:08:38 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/04/10 22:55:07 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_philo	*get_philo(int ac, char **av)
{
	t_philo			*philo;
	int				i;
	int				philo_nbr;
	pthread_mutex_t	*fork;

	philo_nbr = ft_atoi(av[1]);
	philo = malloc(sizeof(t_philo) * philo_nbr);
	// if (!ph)
		//
	fork = malloc(sizeof(int) * philo_nbr);
	// if (!fork)
		//
	i = 0;
	while (i < philo_nbr)
	{
		philo[i].nbr = philo_nbr;
		philo[i].t_die = ft_atoi(av[2]);
		philo[i].t_eat = ft_atoi(av[3]);
		philo[i].t_sleep = ft_atoi(av[4]);
		if (ac == 6)
			philo[i].nbr_eat = ft_atoi(av[5]);
		philo[i].index = i;
		philo[i].fork = fork;
		gettimeofday(&philo[i].time, NULL);
		i++;
	}
	return (philo);
}

unsigned long	get_time(struct timeval time, t_philo *philo)
{
	return ((time.tv_sec * 1000 + time.tv_usec / 1000)
		- (philo->time.tv_sec * 1000 + philo->time.tv_usec / 1000));
}