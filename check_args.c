/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: barae <barae@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:28:23 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/04/18 02:27:27 by barae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	print_return(char *s1, char* s2)
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
			if (str[i] == '+' && i == 0)
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
		if (!is_number(av[i]))
		{
			print_return(av[i],
				"is not a number or it's a negative number");
			break ;
		}
		i++;
	}
	return (1);
}