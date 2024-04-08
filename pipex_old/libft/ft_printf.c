/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:56:02 by jkarras           #+#    #+#             */
/*   Updated: 2023/11/24 16:15:42 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_type(va_list args, char *s, size_t *counter)
{
	if (*s == 'c')
		ft_putchar_p(va_arg(args, int), counter);
	else if (*s == 's')
		ft_putstr_p(va_arg(args, char *), counter);
	else if (*s == 'd' || *s == 'i')
		ft_putnbr_p(va_arg(args, int), counter);
	else if (*s == '%')
		ft_putchar_p('%', counter);
	else if (*s == 'u')
		ft_putu_p(va_arg(args, unsigned), counter);
	else if (*s == 'x' || *s == 'X')
	{
		if (*s == 'x')
			ft_phex_p(va_arg(args, unsigned int), counter, "0123456789abcdef");
		else
			ft_phex_p(va_arg(args, unsigned int), counter, "0123456789ABCDEF");
	}
	else if (*s == 'p')
		ft_putvoidhex_p(va_arg(args, void *), counter);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	counter;

	if (s == NULL)
		return (-1);
	va_start(args, s);
	counter = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			ft_check_type(args, (char *)s, &counter);
			s++;
		}
		else
		{
			ft_putchar_p(*s, &counter);
			s++;
		}
	}
	va_end(args);
	return (counter);
}
