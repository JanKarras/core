/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path_is_valid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:37:12 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/22 16:43:53 by jkarras          ###   ########.fr       */
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

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			ft_putchar_fd(map[i][j], 1);
			j++;
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
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

int	get_p_x(char **map, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_p_y(char **map, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_e_x(char **map, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
				return (j);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_e_y(char **map, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
				return (i);
			j++;
		}
		i++;
	}
	return (0);
}

int	get_collectables_count(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
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
