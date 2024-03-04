/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:42:11 by jkarras           #+#    #+#             */
/*   Updated: 2024/03/04 14:30:39 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_img_index(char c)
{
	if (c == '0')
		return (0);
	if (c == '1')
		return (1);
	if (c == 'C')
		return (2);
	if (c == 'E')
		return (3);
	if (c == 'P')
		return (4);
	return (0);
}

int	draw_map(t_data *data)
{
	int		i;
	int		j;
	float	width;
	float	height;

	i = 0;
	width = WINDOW_WIDTH / check_size(data->argv);
	height = WINDOW_HEIGHT / get_height(data->argv);
	while ((data->argv)[i] != NULL)
	{
		j = 0;
		while ((data->argv)[i][j] != '\0')
		{
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				(data->img_ptrs)[get_img_index((data->argv)[i][j])
			], j * width, i * height);
			j++;
		}
		i++;
	}
	return (0);
}

void	find_player_pos(t_data *data, int keycode)
{
	int	i;
	int	j;

	i = 0;
	while ((data->argv)[i] != NULL)
	{
		j = 0;
		while ((data->argv)[i][j] != '\0')
		{
			if ((data->argv)[i][j] == 'P')
				break ;
			j++;
		}
		if ((data->argv)[i][j] == 'P')
			break ;
		i++;
	}
	move(data, i, j, keycode);
}
