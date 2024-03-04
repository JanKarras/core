/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resize_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 19:37:47 by jkarras           #+#    #+#             */
/*   Updated: 2024/03/04 15:55:12 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_data_addr(void *img_ptr, int *sz_l)
{
	int		bits;
	int		endian;
	char	*data_addr;

	data_addr = mlx_get_data_addr(img_ptr, &bits, sz_l, &endian);
	if (data_addr == NULL)
		return (NULL);
	return (data_addr);
}

void	resize(t_data *data, int szn, int szo, int i)
{
	int	x_ratio;
	int	y_ratio;
	int	x2;
	int	y2;
	int	j;

	x_ratio = (100 * 65536) / *data->width;
	y_ratio = (100 * 65536) / *data->height;
	while (i < *data->height)
	{
		j = 0;
		while (j < *data->width)
		{
			x2 = ((j * x_ratio) / 65536);
			y2 = ((i * y_ratio) / 65536);
			data->n[(i * szn) + j * 4] = data->o[(y2 * szo) + x2 * 4];
			data->n[(i * szn) + j * 4 + 1] = data->o[(y2 * szo) + x2 * 4 + 1];
			data->n[(i * szn) + j * 4 + 2] = data->o[(y2 * szo) + x2 * 4 + 2];
			data->n[(i * szn) + j * 4 + 3] = data->o[(y2 * szo) + x2 * 4 + 3];
			j++;
		}
		i++;
	}
}

int	rezise_img(t_data *data, int new_width, int new_height, int i)
{
	int		size_line_old;
	int		size_line_new;
	void	*tmp_img_ptr;

	data->o = get_data_addr((data->img_ptrs)[i], &size_line_old);
	if (data->o == NULL)
		return (-1);
	tmp_img_ptr = mlx_new_image(data->mlx_ptr, new_width, new_height);
	if (tmp_img_ptr == NULL)
		return (-1);
	data->n = get_data_addr(tmp_img_ptr, &size_line_new);
	if (data->n == NULL)
		return (mlx_destroy_image(data->mlx_ptr, tmp_img_ptr), -1);
	resize(data, size_line_new, size_line_old, 0);
	mlx_destroy_image(data->mlx_ptr, (data->img_ptrs)[i]);
	(data->img_ptrs)[i] = tmp_img_ptr;
	return (0);
}
