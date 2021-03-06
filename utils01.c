/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:42:45 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/05/09 13:23:37 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_l_int	get_time(void)
{
	t_time_val	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

void	ft_usleep(t_l_int time_to_sleep)
{
	t_l_int	s_time;

	s_time = get_time();
	while ((get_time() - s_time) < time_to_sleep)
		usleep(200);
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				sign;
	int				result;

	if (!*str)
		return (0);
	i = 0;
	sign = 1;
	while (*(str + i) == ' ' || *(str + i) == '\t' || *(str + i) == '\r'
		|| *(str + i) == '\n' || *(str + i) == '\v' || *(str + i) == '\f')
		i++;
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			sign *= -1;
		i++;
	}
	result = 0;
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		result = result * 10 + (*(str + i) - '0');
		i++;
	}
	return (sign * result);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	create_threads(t_philo *philo, int i,
	void *(*routine)(void *))
{
	while (i < philo->data->philo_nbr)
	{
		if (pthread_create(&philo[i].thread, NULL, routine, philo + i))
		{
			printf("Error: unable to create thread\n");
			return (0);
		}
		i += 2;
	}
	return (1);
}
