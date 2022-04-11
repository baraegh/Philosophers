/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:15:47 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/04/10 23:06:20 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	take_fork(t_philo *philo)
{
	struct timeval	time;
	
	gettimeofday(&time, NULL);
	printf("%lu	%d	has taken a fork\n", get_time(time, philo), philo->index + 1);
}

void	eat(t_philo *philo)
{
	struct timeval	time;
	gettimeofday(&time, NULL);
	printf("%lu	%d	is eating\n", get_time(time, philo), philo->index + 1);
	usleep(philo->t_eat);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	pthread_mutex_lock(&philo->fork[philo->index]);
	take_fork(philo);
	pthread_mutex_lock(&philo->fork[(philo->index + 1) % philo->nbr]);
	take_fork(philo);
	eat(philo);
	pthread_mutex_unlock(&philo->fork[(philo->index + 1) % philo->nbr]);
	pthread_mutex_unlock(&philo->fork[philo->index]);
	return (NULL);
}

void	philosophers(t_philo *philo)
{
	int		i;

	i = 0;
	while (i < philo->nbr)
		pthread_mutex_init(&philo->fork[i++], NULL);
	i = 0;
	while (i < philo->nbr)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, philo + i))
		{
			printf("Error: unable to create thread\n");
			break ;
		}
		i++;
	}
	i = 0;
	while (i < philo->nbr)
	{
		if (pthread_join(philo[i++].thread, NULL))
		{
			printf("Error: unable to join thread\n");
			break ;
		}
	}
	i = 0;
	while (i < philo->nbr)
		pthread_mutex_destroy(&philo->fork[i++]); 
}

int	main(int ac, char **av)
{
	if (ac == 6 || ac == 5)
	{
		if (!check_av(av, ac))
			return (0);
		philosophers(get_philo(ac, av));
	}
	else
		printf("arguments number different than 5\n");
	return (0);
}