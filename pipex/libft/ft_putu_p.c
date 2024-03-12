/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putu_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:05:33 by jkarras           #+#    #+#             */
/*   Updated: 2023/11/24 15:38:34 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putu_p(unsigned int n, size_t *counter)
{
	if (n >= 10)
		ft_putu_p(n / 10, counter);
	ft_putchar_p(n % 10 + '0', counter);
}
