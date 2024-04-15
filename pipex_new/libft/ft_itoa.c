/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:05:22 by jkarras           #+#    #+#             */
/*   Updated: 2023/11/20 18:44:35 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_digits(int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	fill_arr(char *str, long int nb, int digits)
{
	str[digits] = '\0';
	digits--;
	while (digits >= 0)
	{
		str[digits] = nb % 10 + '0';
		nb = nb / 10;
		digits--;
	}
}

static void	fill_arr_neg(char *str, long int nb, int digits)
{
	str[0] = '-';
	str[digits] = '\0';
	digits--;
	while (digits > 0)
	{
		str[digits] = nb % 10 + '0';
		nb = nb / 10;
		digits--;
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	long int	nb;
	int			digits;

	if (n == 0)
		digits = 1;
	else
		digits = get_digits(n);
	if (n < 0)
		digits = digits + 1;
	str = (char *)malloc(sizeof(char) * (digits + 1));
	if (str == NULL)
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	nb = n;
	if (n < 0)
		fill_arr_neg(str, nb * (-1), digits);
	else if (n > 0)
		fill_arr(str, nb, digits);
	return (str);
}
