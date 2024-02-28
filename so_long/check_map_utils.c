/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:01:29 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/20 15:03:48 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	my_ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int	get_height(char **map)
{
	int	height;

	height = 0;
	while (map[height] != NULL)
		height++;
	return (height);
}

int	check_char(char c)
{
	if (c == '0')
		return (0);
	else if (c == '1')
		return (0);
	else if (c == 'C')
		return (0);
	else if (c == 'P')
		return (0);
	else if (c == 'E')
		return (0);
	else
		return (-1);
}
