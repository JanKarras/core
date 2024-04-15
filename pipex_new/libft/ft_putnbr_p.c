/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:41:56 by jkarras           #+#    #+#             */
/*   Updated: 2023/11/24 15:37:25 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_p(int n, size_t *counter)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_p('-', counter);
		nb = n * (-1);
	}
	else
		nb = n;
	ft_putu_p(nb, counter);
}
