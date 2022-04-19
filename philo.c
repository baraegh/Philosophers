/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barae <barae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:15:47 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/04/19 03:01:21 by barae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_status(t_philo *philo, char *status)
{

	printf("%llu	%d	%s\n", (get_time() - philo->starting_time) / 1000, philo->index + 1, status);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork[philo->index]);
	print_status(philo, "has taken the left fork");
	pthread_mutex_lock(&philo->fork[(philo->index + 1) % philo->data->nbr]);
	print_status(philo, "has taken the right fork");
	print_status(philo, "is eating");
	ft_usleep(philo->data->t_eat);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->fork[philo->index]);
	pthread_mutex_unlock(&philo->fork[(philo->index + 1) % philo->data->nbr]);
	print_status(philo, "is sleeping");
	ft_usleep(philo->data->t_sleep);
	if (!(philo->data->death))
		print_status(philo, "is thinking");
}

void	*routine(void *arg)
{
	t_philo	*philo;
	// t_data	*data;

	philo = (t_philo *) arg;
	// data = philo->data;
	if (philo->index % 2)
		ft_usleep(10);
	while (1)
	{
		// if (!(data->death))
		// 	break ;
		eat(philo);
	}
	return (NULL);
}

void	philosophers(t_philo *philo)
{
	int		i;

	i = 0;
	while (i < philo->data->nbr)
		pthread_mutex_init(&philo->fork[i++], NULL);
	i = 0;
	while (i < philo->data->nbr)
	{
		if (pthread_create(&philo[i].thread, NULL, &routine, philo + i))
		{
			printf("Error: unable to create thread\n");
			break ;
		}
		i ++;
	}
	checking_death(philo);
	while (i < philo->data->nbr)
		pthread_mutex_destroy(&philo->fork[i++]); 
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 6 || ac == 5)
	{
		if (!check_args(av, ac))
			return (0);
		data = malloc(sizeof(t_data));
		// if (!data)
		// 	return
		if (!init_data(ac, av, data))
			return (0);
		philosophers(data->philo);
	}
	else
		printf("Error: bad arguments number\n");
	return (0);
}