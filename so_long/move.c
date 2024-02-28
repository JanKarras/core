/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:40:00 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/28 19:40:24 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data, int i, int j)
{
	if ((data->argv)[i - 1][j] == 'E' && (*data->col) == 0)
	{
		(*data->move_count)++;
		ft_printf("%i\n", (*data->move_count));
		on_destroy(data);
	}
	if ((data->argv)[i - 1][j] == 'C')
		(*data->col)--;
	(data->argv)[i - 1][j] = 'P';
	(data->argv)[i][j] = '0';
	(*data->move_count)++;
	ft_printf("%i\n", (*data->move_count));
}

void	move_left(t_data *data, int i, int j)
{
	if ((data->argv)[i][j - 1] == 'E' && (*data->col) == 0)
	{
		(*data->move_count)++;
		ft_printf("%i\n", (*data->move_count));
		on_destroy(data);
	}
	if ((data->argv)[i][j - 1] == 'C')
		(*data->col)--;
	(data->argv)[i][j - 1] = 'P';
	(data->argv)[i][j] = '0';
	(*data->move_count)++;
	ft_printf("%i\n", (*data->move_count));
}

void	move_down(t_data *data, int i, int j)
{
	if ((data->argv)[i + 1][j] == 'E' && (*data->col) == 0)
	{
		(*data->move_count)++;
		ft_printf("%i\n", (*data->move_count));
		on_destroy(data);
	}
	if ((data->argv)[i + 1][j] == 'C')
		(*data->col)--;
	(data->argv)[i + 1][j] = 'P';
	(data->argv)[i][j] = '0';
	(*data->move_count)++;
	ft_printf("%i\n", (*data->move_count));
}

void	move_right(t_data *data, int i, int j)
{
	if ((data->argv)[i][j + 1] == 'E' && (*data->col) == 0)
	{
		(*data->move_count)++;
		ft_printf("%i\n", (*data->move_count));
		on_destroy(data);
	}
	if ((data->argv)[i][j + 1] == 'C')
		(*data->col)--;
	(data->argv)[i][j + 1] = 'P';
	(data->argv)[i][j] = '0';
	(*data->move_count)++;
	ft_printf("%i\n", (*data->move_count));
}

void	move(t_data *data, int i, int j, int keycode)
{
	if (keycode == 119 && (data->argv)[i - 1][j] != '1')
		move_up(data, i, j);
	if (keycode == 97 && (data->argv)[i][j - 1] != '1')
		move_left(data, i, j);
	if (keycode == 115 && (data->argv)[i + 1][j] != '1')
		move_down(data, i, j);
	if (keycode == 100 && (data->argv)[i][j + 1] != '1')
		move_right(data, i, j);
	if ((data->argv)[(*data->e_y)][(*data->e_x)] != 'P')
		(data->argv)[(*data->e_y)][(*data->e_x)] = 'E';
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw_map(data);
}
