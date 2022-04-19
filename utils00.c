/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barae <barae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:08:38 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/04/19 02:26:41 by barae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

uli	get_time(void)
{
	timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

int	init_data(int ac, char **av, t_data *data)
{
	int				i;
	int				philo_nbr;
	pthread_mutex_t	*fork;

	philo_nbr = ft_atoi(av[1]);
	// if (philo_nbr <= 0)
	// 	return
	data->philo = malloc(sizeof(t_philo) * philo_nbr);
	// if (!ph)
		//
	fork = malloc(sizeof(pthread_mutex_t) * philo_nbr);
	// if (!fork)
		//
	data->nbr = philo_nbr;
	data->t_die = ft_atoi(av[2]) * 1000;
	data->t_eat = ft_atoi(av[3]) * 1000;
	data->t_sleep = ft_atoi(av[4]) * 1000;
	data->death = 0;
	if (ac == 6)
		data->nbr_eat = ft_atoi(av[5]);
	else
		data->nbr_eat = -1;
	i = 0;
	while (i < philo_nbr)
	{
		data->philo[i].index = i;
		data->philo[i].starting_time = get_time();
		data->philo[i].last_meal_time = get_time();
		data->philo[i].fork = fork;
		data->philo[i].data = data;
		i++;
	}
	return (1);
}

// ull	get_time_deff(timeval c_time, timeval p_time)
// {
// 	return ((c_time.tv_sec * 1000 + c_time.tv_usec / 1000)
// 		- (p_time.tv_sec * 1000 + p_time.tv_usec / 1000));
// }

void	ft_usleep(uli time_to_sleep)
{
	uli	c_time;

	c_time = get_time();
	while ((get_time() - c_time) < time_to_sleep)
		usleep(100);
}

void	checking_death(t_philo *philo)
{
	t_data	*data;
	int		i;

	data = philo->data;
	while (1)
	{
		i = 0;
		while (i < data->nbr)
		{
			if (get_time() - data->philo[i].last_meal_time > data->t_die)
			{
				data->death = 1;
				print_status(data->philo + i, "died");
				return ;
			}
			i++;
		}
	}
}
