/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:15:47 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/05/09 13:21:47 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%ld	%d	%s\n",
		(get_time() - philo->starting_time) / 1000,
		philo->index + 1, status);
	if (ft_strcmp(status, "died") != 0)
		pthread_mutex_unlock(&philo->data->print);
}

void	philo_state(t_philo *philo)
{
	pthread_mutex_lock(&philo->fork[philo->index]);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->fork[(philo->index + 1)
		% philo->data->philo_nbr]);
	print_status(philo, "has taken a fork");
	philo->is_eating = 1;
	philo->last_meal_time = get_time();
	print_status(philo, "is eating");
	ft_usleep(philo->data->t_eat);
	philo->nbr_of_time_ate++;
	philo->is_eating = 0;
	print_status(philo, "is sleeping");
	pthread_mutex_unlock(&philo->fork[philo->index]);
	pthread_mutex_unlock(&philo->fork[(philo->index + 1)
		% philo->data->philo_nbr]);
	ft_usleep(philo->data->t_sleep);
	print_status(philo, "is thinking");
}

void	*routine(void *arg)
{
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *) arg;
	data = philo->data;
	while (!data->death
		&& philo->nbr_of_time_ate != data->nbr_eat)
		philo_state(philo);
	return (NULL);
}

void	philosophers(t_philo *philo)
{
	int	i;

	if (!create_threads(philo, 0, &routine))
		return ;
	ft_usleep(100);
	if (!create_threads(philo, 1, &routine))
		return ;
	checking_death(philo);
	i = 0;
	while (i < philo->data->philo_nbr)
		pthread_mutex_destroy(&philo->fork[i++]);
	pthread_mutex_destroy(&philo->data->print);
}

int	main(int ac, char **av)
{
	t_data	*data;

	if (ac == 6 || ac == 5)
	{
		if (!check_args(av, ac))
			return (0);
		data = malloc(sizeof(t_data));
		if (!data)
			return (0);
		if (!init_data(ac, av, data))
			return (0);
		init_mutex(data);
		philosophers(data->philo);
		free(data->philo->fork);
		free(data->philo);
		free(data);
	}
	else
		printf("Error: bad arguments number\n");
	return (0);
}
