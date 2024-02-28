/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:17:51 by jkarras           #+#    #+#             */
/*   Updated: 2023/11/23 16:49:19 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_p(char *s, size_t *counter)
{
	if (s == NULL)
	{
		ft_putstr_p("(null)", counter);
		return ;
	}
	while (*s)
	{
		ft_putchar_p(*s, counter);
		s++;
	}
}
