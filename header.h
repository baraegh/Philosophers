/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barae <barae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:11:26 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/04/20 05:19:14 by barae            ###   ########.fr       */
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

typedef struct timeval timeval;
typedef struct s_data t_data;
typedef long int uli;

typedef struct s_philo
{
	pthread_t		thread;
	int				index;
	int				nbr_of_time_eat;
	int				is_eating;
	uli				starting_time;
	uli				last_meal_time;
	pthread_mutex_t	*fork;
	t_data			*data;
}	t_philo;

struct s_data
{
	t_philo	*philo;
	int		philo_nbr;
	uli		t_die;
	uli		t_eat;
	uli		t_sleep;
	int		nbr_eat;
	int		death;
	pthread_mutex_t	print;
};

int		check_args(char **av, int ac);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_usleep(uli time_to_sleep);
int		init_data(int ac, char **av, t_data *data);
uli		get_time(void);
void	checking_death(t_philo *philo);
void	print_status(t_philo *philo, char *status);
int		ft_strcmp(const char *s1, const char *s2);

#endif