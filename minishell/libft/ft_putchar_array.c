/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:08:16 by jkarras           #+#    #+#             */
/*   Updated: 2024/06/17 15:23:12 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_array(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_putendl_fd(array[i], 1);
		i++;
	}
}
