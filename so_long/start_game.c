/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkarras <jkarras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:27:47 by jkarras           #+#    #+#             */
/*   Updated: 2024/03/05 14:34:24 by jkarras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	on_maximize(t_data *data)
{
	draw_map(data);
	return (0);
}

void	hooks(t_data *data)
{
	mlx_hook(data->win_ptr, 17, 1L << 17, &on_destroy, data);
	mlx_key_hook(data->win_ptr, &key_hooks, data);
	mlx_hook(data->win_ptr, 12, 1L << 15, &on_maximize, data);
}

int	start_game(char **argv)
{
	t_data	*data;

	data = init(argv);
	if (data == NULL)
		return (ft_putendl_fd("Malloc error", 1), -1);
	draw_map(data);
	hooks(data);
	mlx_loop(data->mlx_ptr);
	return (0);
}
