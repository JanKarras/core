/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoidhex_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:36:55 by jkarras           #+#    #+#             */
/*   Updated: 2023/11/23 17:07:19 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printhex_help(unsigned long nb, size_t *counter, const char *s)
{
	if (nb >= 16)
		ft_printhex_help(nb / 16, counter, "0123456789abcdef");
	ft_putchar_p(s[nb % 16], counter);
}

void	ft_putvoidhex_p(void *p, size_t *counter)
{
	ft_putstr_p("0x", counter);
	ft_printhex_help((unsigned long)p, counter, "0123456789abcdef");
}
