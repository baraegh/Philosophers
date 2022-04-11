/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-ghan <eel-ghan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:42:45 by eel-ghan          #+#    #+#             */
/*   Updated: 2022/04/05 03:05:22 by eel-ghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_result(const char *str, int i, int sign)
{
	int	result;
	int	count;

	result = 0;
	count = 1;
	while (*(str + i))
	{
		if (*(str + i) >= '0' && *(str + i) <= '9')
		{
			result = result * 10 + (*(str + i) - '0');
			count++;
		}
		else
			break ;
		i++;
	}
	if (count >= 20 && sign > 0)
		return (-1);
	else if (count >= 20 && sign < 0)
		return (0);
	return (result);
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	int				sign;

	if (!*str)
		return (0);
	i = 0;
	sign = 1;
	while (*(str + i) == ' ' || *(str + i) == '\t' || *(str + i) == '\r'
		|| *(str + i) == '\n' || *(str + i) == '\v'
		|| *(str + i) == '\f')
		i++;
	if (*(str + i) == '-')
	{
		sign *= -1;
		i++;
	}
	else if (*(str + i) == '+')
		i++;
	return (sign * ft_result(str, i, sign));
}