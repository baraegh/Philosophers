/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barae <barae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 23:11:26 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/04/28 23:06:00 by barae            ###   ########.fr       */
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

typedef struct timeval time_val;
typedef struct s_data t_data;
typedef long int l_int;

typedef struct s_philo
{
	pthread_t		thread;
	int				index;
	int				nbr_of_time_ate;
	int				is_eating;
	l_int			starting_time;
	l_int			last_meal_time;
	pthread_mutex_t	*fork;
	t_data			*data;
}	t_philo;

struct s_data
{
	t_philo			*philo;
	int				philo_nbr;
	l_int			t_die;
	l_int			t_eat;
	l_int			t_sleep;
	int				nbr_eat;
	int				death;
	pthread_mutex_t	print;
};

int			check_args(char **av, int ac);
int			ft_isdigit(int c);
int			ft_atoi(const char *str);
void		ft_usleep(l_int time_to_sleep);
int			init_data(int ac, char **av, t_data *data);
l_int		get_time(void);
void		checking_death(t_philo *philo);
void		print_status(t_philo *philo, char *status);
int			ft_strcmp(const char *s1, const char *s2);
void		init_mutex(t_data *data);
int			create_threads(t_philo *philo, int i, void *(* routine)(void *));

#endif