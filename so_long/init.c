/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:34:37 by jkarras           #+#    #+#             */
/*   Updated: 2024/03/05 18:43:08 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_img_ptrs(t_data *data, int w, int h)
{
	(data->img_ptrs)[0] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/0.xpm", &w, &h);
	if ((data->img_ptrs)[0] == NULL)
		return (-1);
	(data->img_ptrs)[1] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/1.xpm", &w, &h);
	if ((data->img_ptrs)[1] == NULL)
		return (free_img_ptrs(data, 1), -1);
	(data->img_ptrs)[2] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/c.xpm", &w, &h);
	if ((data->img_ptrs)[2] == NULL)
		return (free_img_ptrs(data, 2), -1);
	(data->img_ptrs)[3] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/e.xpm", &w, &h);
	if ((data->img_ptrs)[3] == NULL)
		return (free_img_ptrs(data, 3), -1);
	(data->img_ptrs)[4] = mlx_xpm_file_to_image
		(data->mlx_ptr, "./img/p.xpm", &w, &h);
	if ((data->img_ptrs)[4] == NULL)
		return (free_img_ptrs(data, 4), -1);
	return (0);
}

int	init_img_ptrs(t_data *data)
{
	data->img_ptrs = (void **)malloc(sizeof(void *) * (5));
	if (data->img_ptrs == NULL)
		return (-1);
	if (get_img_ptrs(data, 0, 0) != 0)
		return (-1);
	if (rezise_img(data, *data->width, *data->height, 0) != 0)
		return (free_img_ptrs(data, 5), -1);
	if (rezise_img(data, *data->width, *data->height, 1) != 0)
		return (free_img_ptrs(data, 5), -1);
	if (rezise_img(data, *data->width, *data->height, 2) != 0)
		return (free_img_ptrs(data, 5), -1);
	if (rezise_img(data, *data->width, *data->height, 3) != 0)
		return (free_img_ptrs(data, 5), -1);
	if (rezise_img(data, *data->width, *data->height, 4) != 0)
		return (free_img_ptrs(data, 5), -1);
	return (0);
}

int	inti_new_width_height(t_data *data)
{
	data->width = (int *)malloc(sizeof(int));
	if (data->width == NULL)
		return (-1);
	data->height = (int *)malloc(sizeof(int));
	if (data->height == NULL)
		return (free(data->width), -1);
	*data->width = WINDOW_WIDTH / check_size(data->argv);
	*data->height = WINDOW_HEIGHT / get_height(data->argv);
	return (0);
}

int	init_col_on_exit(t_data *data)
{
	data->col = (int *)malloc(sizeof(int));
	if (data->col == NULL)
		return (-1);
	(*data->col) = get_collectables_count(data->argv);
	data->e_x = (int *)malloc(sizeof(int));
	if (data->e_x == NULL)
		return (free(data->col), -1);
	data->e_y = (int *)malloc(sizeof(int));
	if (data->e_y == NULL)
		return (free(data->col), free(data->e_x), -1);
	(*data->e_x) = get_e_x(data->argv, get_height(data->argv));
	(*data->e_y) = get_e_y(data->argv, get_height(data->argv));
	data->move_count = (int *)malloc(sizeof(int));
	if (data->move_count == NULL)
		return (free(data->col), free(data->e_x), free(data->e_y), -1);
	(*data->move_count) = 0;
	if (inti_new_width_height(data) != 0)
	{
		free(data->move_count);
		return (free(data->col), free(data->e_x), free(data->e_y), -1);
	}
	return (0);
}

t_data	*init(char **argv)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);
	data->argv = argv;
	if (init_col_on_exit(data) != 0)
		return (free(data), NULL);
	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
		return (free_col_on_exit(data), free(data), NULL);
	if (init_img_ptrs(data) != 0)
		return (free_col_on_exit(data), free(data->mlx_ptr), free(data), NULL);
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "Ape Trouble");
	ft_putnbr_fd((int)WINDOW_WIDTH, 1);
	if (data->win_ptr == NULL)
	{
		free_col_on_exit(data);
		return (free_img_ptrs(data, 5), free(data->mlx_ptr), free(data), NULL);
	}
	return (data);
}
