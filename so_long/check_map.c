/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:59:42 by jkarras           #+#    #+#             */
/*   Updated: 2024/03/05 14:31:17 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char **map)
{
	int	len;
	int	height;

	len = check_size(map);
	if (len == -1 || len < 5)
		return (free_argv(map), ft_putendl_fd("Map is not an regtangle", 1), -1);
	height = get_height(map);
	if (check_walls(map, len, height) != 0)
		return (free_argv(map), ft_putendl_fd("The Map must be sourrounded by walls", 1), -1);
	if (check_player_exit(map, 1, 1) != 0)
		return (free_argv(map), ft_putendl_fd("There must be one Exit and one Player and atleast one Collectable", 1), -1);
	if (check_chars(map) != 0)
		return (free_argv(map), ft_putendl_fd("Other chars than C, E, P, 0, 1 was found in the map", 1), -1);
	if (check_path_is_valid(map, len, height) != 0)
		return (free_argv(map), ft_putendl_fd("No Validpath found", 1), -1);
	return (0);
}

int	check_size(char **map)
{
	int	len;
	int	i;

	len = my_ft_strlen(map[0]);
	i = 0;
	while (map[i] != NULL)
	{
		if (len != my_ft_strlen(map[i]))
			return (-1);
		i++;
	}
	return (len);
}

int	check_walls(char **map, int len, int height)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (map[0][i] != '1' || (map[height - 1][i]) != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (map[i] != NULL)
	{
		if (map[i][0] != '1' || map[i][len - 1] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_player_exit(char **map, int i, int j)
{
	int	player;
	int	exit;
	int	collect;

	player = 0;
	exit = 0;
	collect = 0;
	while (map[i] != NULL)
	{
		j = 1;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				player++;
			if (map[i][j] == 'E')
				exit++;
			if (map[i][j] == 'C')
				collect++;
			j++;
		}
		i++;
	}
	if (player != 1 || exit != 1 || collect == 0)
		return (-1);
	return (0);
}

int	check_chars(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (check_char(map[i][j]) == -1)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}
