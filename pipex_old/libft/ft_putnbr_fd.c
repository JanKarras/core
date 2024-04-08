/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:11:10 by jkarras           #+#    #+#             */
/*   Updated: 2023/11/17 18:39:14 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_number(int n, int fd)
{
	if (n == 0)
	{
		write(fd, "0", 1);
		return (0);
	}
	else if (n < 0)
	{
		n = n * (-1);
		write(fd, "-", 1);
		return (n);
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str[12];
	int		i;
	int		number;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	n = check_number(n, fd);
	i = 0;
	while (n > 0)
	{
		number = n % 10;
		n = n / 10;
		str[i] = number + '0';
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(fd, &str[i], 1);
		i--;
	}
}
