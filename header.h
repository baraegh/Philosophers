/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:11:26 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/04/09 01:37:48 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				nbr;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nbr_eat;
	int				index;
	pthread_mutex_t	*fork;
	struct timeval	time;
}	t_philo;

int		check_av(char **av, int ac);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
t_philo	*get_philo(int ac, char **av);
unsigned long	get_time(struct timeval time, t_philo *philo);

#endif