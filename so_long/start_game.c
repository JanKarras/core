/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:27:47 by jkarras           #+#    #+#             */
/*   Updated: 2024/02/27 21:16:14 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_collectables_count(char **map);
int	get_e_x(char **map, int height);
int	get_e_y(char **map, int height);


void	free_col_on_exit(t_data *data)
{
	free(data->col);
	free(data->e_x);
	free(data->e_y);
	free(data->move_count);
}

void	free_img_ptrs(t_data *data, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free((data->img_ptrs)[i]);
		i++;
	}
	free(data->img_ptrs);
}

int	on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_argv(data->argv);
	free_col_on_exit(data);
	free_img_ptrs(data, 5);
	free(data);
	exit(0);
	return (0);
}

void	ft_error(t_data *data)
{
	ft_putendl_fd("Error", 1);
	on_destroy(data);
}

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
	int	i;
	int	j;
	int	width;
	int	height;

	i = 0;
	width = 720 / check_size(data->argv);
	height = 480 / get_height(data->argv);
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

int	key_hooks(int keycode, t_data *data)
{
	if (keycode == 65307)
		on_destroy(data);
	if (keycode == 119)
		find_player_pos(data, keycode);
	if (keycode == 97)
		find_player_pos(data, keycode);
	if (keycode == 115)
		find_player_pos(data, keycode);
	if (keycode == 100)
		find_player_pos(data, keycode);
	return (0);
}

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


int	resize_images(t_data *data, int new_width, int new_height)
{
	char	*img_data_old;
	char	*img_data_new;
	int		bits;
	int		size_line_old;
	int		size_line_new;
	int		endian;
	void	*mlx_ptr = data->mlx_ptr;
	int	t;
	int	s;
	(data->img_ptrs)[0] = mlx_xpm_file_to_image(data->mlx_ptr, "./img/0.xpm", &t, &s);
	if ((data->img_ptrs)[0] == NULL)
		return (ft_putendl_fd("Error", 1), 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, (data->img_ptrs)[0], 300, 300);
    img_data_old = mlx_get_data_addr((data->img_ptrs)[0], &bits, &size_line_old, &endian);

	void *tmp = (data->img_ptrs)[0];

    (data->img_ptrs)[0] = mlx_new_image(mlx_ptr, new_width, new_height);

    img_data_new = mlx_get_data_addr((data->img_ptrs)[0], &bits, &size_line_new, &endian);
 	int x_ratio = (size_line_old << 16) / new_width + 1;
	int y_ratio = (size_line_old << 16) / new_height + 1;

    int x2, y2;
    for (int i = 0; i < new_height; i++) {
        for (int j = 0; j < new_width; j++) {
            x2 = ((j * x_ratio) >> 16);
            y2 = ((i * y_ratio) >> 16);
            img_data_new[(i * size_line_new) + j * 4] = img_data_old[(y2 * size_line_old) + x2 * 4];
            img_data_new[(i * size_line_new) + j * 4 + 1] = img_data_old[(y2 * size_line_old) + x2 * 4 + 1];
            img_data_new[(i * size_line_new) + j * 4 + 2] = img_data_old[(y2 * size_line_old) + x2 * 4 + 2];
            img_data_new[(i * size_line_new) + j * 4 + 3] = img_data_old[(y2 * size_line_old) + x2 * 4 + 3];
        }
    }
    mlx_destroy_image(mlx_ptr, tmp);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, (data->img_ptrs)[0], 100, 100);
    return 0;
}


int	init_img_ptrs(t_data *data)
{
	data->img_ptrs = (void **)malloc(sizeof(void *) * (5));
	if (data->img_ptrs == NULL)
		return (-1);
	// if (get_img_ptrs(data, 0, 0) != 0)
	// 	return (-1);
	// if (resize_images(data, 720 / check_size(data->argv), 480 / get_height(data->argv)) != 0)
	// 	return (free_img_ptrs(data, 5), -1);
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
	data->win_ptr = mlx_new_window(data->mlx_ptr, 720, 480, "Ape Trouble");
	if (data->win_ptr == NULL)
	{
		free_col_on_exit(data);
		return (free_img_ptrs(data, 5), free(data->mlx_ptr), free(data), NULL);
	}
	return (data);
}

void	hooks(t_data *data)
{
	mlx_hook(data->win_ptr, 17, 1L << 17, &on_destroy, data);
	mlx_key_hook(data->win_ptr, &key_hooks, data);
}

int	start_game(char **argv)
{
	t_data	*data;

	data = init(argv);
	if (data == NULL)
		return (-1);
	// if (draw_map(data) != 0)
	// 	ft_error(data);
	resize_images(data, 720 / check_size(data->argv), 480 / get_height(data->argv));
	hooks(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
