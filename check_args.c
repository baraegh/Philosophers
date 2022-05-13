/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:28:23 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/05/09 13:14:10 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	print_return(char *s1, char *s2)
{
	printf("%s: %s\n", s1, s2);
	return (0);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if ((str[i] == '+' || str[i] == '-')
				&& i == 0)
			{
				i++;
				continue ;
			}
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_args(char **av, int ac)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_number(av[i])
			|| ft_atoi(av[i]) <= 0)
			return (print_return("wrong input", av[i]));
		i++;
	}
	return (1);
}
