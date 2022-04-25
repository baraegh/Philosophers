/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils00.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barae <barae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 01:08:38 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/04/25 02:51:59 by barae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	init_philos(t_data *data)
{
	pthread_mutex_t	*fork;
	int				i;

	fork = malloc(sizeof(pthread_mutex_t) * data->philo_nbr);
	if (!fork)
		return (0);
	i = 0;
	while (i < data->philo_nbr)
	{
		data->philo[i].index = i;
		data->philo[i].nbr_of_time_ate = 0;
		data->philo[i].is_eating = 0;
		data->philo[i].starting_time = get_time();
		data->philo[i].last_meal_time = get_time();
		data->philo[i].fork = fork;
		data->philo[i].data = data;
		i++;
	}
	return (1);
}

int	init_data(int ac, char **av, t_data *data)
{
	int	philo_nbr;

	philo_nbr = ft_atoi(av[1]);
	data->philo = malloc(sizeof(t_philo) * philo_nbr);
	if (!data->philo)
		return (0);
	data->philo_nbr = philo_nbr;
	data->t_die = ft_atoi(av[2]) * 1000;
	data->t_eat = ft_atoi(av[3]) * 1000;
	data->t_sleep = ft_atoi(av[4]) * 1000;
	data->death = 0;
	if (ac == 6)
		data->nbr_eat = ft_atoi(av[5]);
	else
		data->nbr_eat = -1;
	if (!init_philos(data))
		return (0);
	retturn (1);
}

int	is_all_ate(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		if (data->philo[i].nbr_of_time_ate < data->nbr_eat)
			return (0);
		i++;
	}
	return (1);
}

void	checking_death(t_philo *philo)
{
	t_data	*data;
	int		i;

	data = philo->data;
	i = 0;
	while (1)
	{
		i %= data->philo_nbr;
		if (get_time() - data->philo[i].last_meal_time >= data->t_die
			&& !data->philo[i].is_eating)
		{
			data->death = 1;
			print_status(data->philo + i, "died");
			return ;
		}
		if (data->nbr_eat != -1 && is_all_ate(data))
		{
			pthread_mutex_lock(&philo->data->print);
			return ;
		}
		i++;
	}
}

void	init_mutex(t_data *data)
{
	int	i;

	pthread_mutex_init(&data->print, NULL);
	i = 0;
	while (i < data->philo_nbr)
		pthread_mutex_init(&data->philo->fork[i++], NULL);
}