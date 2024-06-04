/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 13:27:11 by jkarras           #+#    #+#             */
/*   Updated: 2024/06/04 15:47:54 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

void	ft_putnbr_fd(size_t n)
{
	char	tmp;

	if (n >= 10)
		ft_putnbr_fd(n / 10);
	tmp = n % 10 + '0';
	write(1, &tmp, 1);
}

size_t	get_time(void)
{
	struct timeval	tv;
	size_t			millosecs;

	if (gettimeofday(&tv, NULL) != 0)
		return (0);
	millosecs = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (millosecs);
}

size_t	atosize_t(char *s)
{
	size_t	i;
	size_t	nb;

	if (s == NULL || *s == '\0')
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	i = 0;
	nb = 0;
	while (s[i])
	{
		nb = nb + s[i] - '0';
		if (s[i + 1] != '\0')
			nb = nb * 10;
		i++;
	}
	return (nb);
}
