/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:35:51 by jkarras           #+#    #+#             */
/*   Updated: 2023/11/20 13:15:38 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_spaces(const char *str)
{
	if (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
	{
		return (1);
	}
	else
		return (0);
}

static int	calc_return(int number, const char *str)
{
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + *str - '0';
		str++;
	}
	return (number);
}

int	ft_atoi(const char *str)
{
	int	minus_count;
	int	number;
	int	val;

	val = 1;
	while (ft_check_spaces(str) == 1)
		str++;
	if (*str == '-')
		val = -1;
	minus_count = 0;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-' || *str == '+')
			minus_count++;
		str++;
	}
	if (minus_count > 1)
		return (0);
	number = calc_return(0, str);
	if (minus_count == 1)
		return (number * val);
	else
		return (number);
}
