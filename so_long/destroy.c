/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:30:48 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/28 20:35:32 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_col_on_exit(t_data *data)
{
	free(data->col);
	free(data->e_x);
	free(data->e_y);
	free(data->move_count);
	free(data->height);
	free(data->width);
}

void	free_img_ptrs(t_data *data, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		mlx_destroy_image(data->mlx_ptr, (data->img_ptrs)[i]);
		i++;
	}
	free(data->img_ptrs);
}

int	on_destroy(t_data *data)
{
	free_img_ptrs(data, 5);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_argv(data->argv);
	free_col_on_exit(data);
	free(data);
	exit(0);
	return (0);
}

void	ft_error(t_data *data)
{
	ft_putendl_fd("Error", 1);
	on_destroy(data);
}
