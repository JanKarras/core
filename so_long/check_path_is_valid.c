/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_is_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:37:12 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/28 19:31:20 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_argv(char **argv, int len, int height)
{
	char	**argv_copy;
	int		i;

	argv_copy = (char **)malloc(sizeof(char *) * (height + 1));
	if (argv_copy == NULL)
		return (NULL);
	i = 0;
	while (i < height)
	{
		argv_copy[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (argv_copy[i] == NULL)
			return (free_argv(argv_copy), NULL);
		ft_strlcpy(argv_copy[i], argv[i], len + 1);
		i++;
	}
	argv_copy[i] = NULL;
	return (argv_copy);
}

int	recrusiv_check(int x, int y, char **copy_argv, int col)
{
	if (x < 0 || y < 0 || copy_argv[y][x] == '1' || copy_argv[y][x] == 'v')
		return (col);
	if (copy_argv[y][x] == 'C')
		col--;
	copy_argv[y][x] = 'v';
	col = recrusiv_check(x + 1, y, copy_argv, col);
	col = recrusiv_check(x - 1, y, copy_argv, col);
	col = recrusiv_check(x, y + 1, copy_argv, col);
	col = recrusiv_check(x, y - 1, copy_argv, col);
	return (col);
}

int	check_path_is_valid(char **argv, int len, int height)
{
	char	**map;
	int		x;
	int		y;
	int		col;

	map = copy_argv(argv, len, height);
	if (map == NULL)
		return (-1);
	x = get_e_x(map, height);
	y = get_e_y(map, height);
	col = get_collectables_count(map);
	col = recrusiv_check(get_p_x(map, height), get_p_y(map, height), map, col);
	if (map[y][x] != 'v' || col != 0)
	{
		free_argv(map);
		return (-1);
	}
	return (free_argv(map), 0);
}
